/*
	Developed by:Marion Z. Owera
	Lucky Nico Solayao
	Roy Romero
	Andrea Caparas
	Benedick Gonzales
	Darren Roldan
	
	Date Written: March 21,2017
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define Error 0//
#define Number 1//
#define String 2//
#define Symbol 3//
#define Method 4//
#define Operator 5//
#define Constant 6//
#define Identifier 7//
#define Delimiter 8//
char *token_array[]={"ERROR","NUMBER","STRING","SYMBOL","METHOD","OPERATOR","CONSTANT","IDENTIFIER","DELIMITER"};
int token_count[9];
int iswspace(char ch){
	return (ch==' '||ch=='\n'||ch=='\t');
}

void libre(char *meme){
	if (meme==NULL){
		return;
	}
	while (*meme!=0){
		*meme++=0;
	}
}

//usable in Number
int isadigit(char ch){
	return ch>='0'&&ch<='9';
}

int issymbol(char ch){
	return !(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')&&ch!='$'&&ch!='_';
}

int isletter(char ch){
	return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}

char *skipwspace(char *code){
	char *temp;
	for (temp=code;iswspace(*temp);*temp++);
	return temp;
}

char *getline(){
	size_t size=100;
	char *line=(char*)malloc(size),*temp=line,ch;
	
	while ((ch=getc(stdin))!='\n'){
		*temp++=ch;
		if (--size==0){
			line=(char*)realloc(line,size+=100);
		}
	}
	*temp=0;
	return line;
}

char *getcode(){
	size_t size=200;
	char *code=(char*)malloc(size),*temp=code,*line;
	*code=0;
	while (1){
		printf(">>>");
		line=getline();
		if (*line==0){
			break;
		}
		while (*line!=0){
			*temp++=*line++;
			if (--size<=0){
				code=(char*)realloc(code,size+=100);
			}
		}
		*temp++='\n';
		if (--size<=0){
			code=(char*)realloc(code,size+=200);
		}
	}
	*temp=0;
	return code;
}

char *readFile(char *input_file_name){
    char *file_contents;
	long input_file_size;
	FILE *input_file = fopen(input_file_name, "rb");
	if (input_file==NULL){
		return NULL;
	}
	fseek(input_file, 0, SEEK_END);
	input_file_size = ftell(input_file);
	rewind(input_file);
	file_contents = (char*)malloc(input_file_size * (sizeof(char)));
	fread(file_contents, sizeof(char), input_file_size, input_file);
	fclose(input_file);
	file_contents[input_file_size]=0;
	return file_contents;
}

char *nextNumber(char *code,char *lexeme,int *token){
	char *temp=lexeme;
	
	if (
		*code=='-'&& (isadigit(*(code+1)) || (*(code+1)=='.'&&isadigit(*(code+2))))
		||(*code=='.'&&isadigit(*(code+1)))
		||isadigit(*code)
	){
		if (*code=='-'){
			*temp++=*code++;
		}
		while (isadigit(*code)||isletter(*code)||*code=='_'||*code=='$'){
			*temp++=*code++;
		}
		if (*code=='.'){
			*temp++=*code++;
		}
		while (isadigit(*code)||isletter(*code)||*code=='_'||*code=='$'){
			*temp++=*code++;
		}
		*temp=0;
		*token=Number;
	}
	
	return code;
}

char *nextString(char *code,char *lexeme,int *token){
	char *temp=lexeme;
	//if a String candidate
	if (*code=='\''||*code=='\"'){
		char ch=*code;
		*temp++=*code++;
		while (*code!=ch){
			if (*code==0||*code=='\n'){
				*token=Error;
				*temp=0;
				return code;
			}
			if (*code=='\\'){
				if (*(code+1)=='n'){
					*token=Error;
					*temp=0;
					return code;
				}
				*temp++=*code++;
			}
			*temp++=*code++;
		}
		*temp++=*code++;
		
		*temp=0;
		*token=String;
		return code;
	}
	
	//if not a string
	return code;
}
char *nextSymbol(char *code,char *lexeme,int *token){
	char *temp=lexeme;
	//if a Single Symbol candidate
	if (!((*code>='a'&&*code<='z')||(*code>='A'&&*code<='Z')||(*code>='0'&&*code<='9')||*code=='$'||*code=='_')){
		*temp++=*code++;
		*temp=0;
		*token=Symbol;
		return code;
	}
	
	//if not a Symbol
	return code;
}

char *ltemp,*ctemp;
int max,ctr;
char *constant[]={"True","False","None","Pi","NaN","Infinity"};
char *oprtr[]={"Add","Sub","Pow","Div","FDiv","Mul","Mod","Inc","Dec",
		"Band","Bor","Bxor","Not","Neq","Eq","Gt","Lt","Or","And",
		"In","Loop","Is","Go","During","Shift","Out","Pause"};
char *nextIdentifier(char *code,char *lexeme,int *token){
	if (*code==0){
		*token=-1;
		return code;
	}
	ltemp=lexeme;
	ctemp=code;
	if (*ctemp=='_'||*ctemp=='$'||isletter(*ctemp)){
		while (*ctemp=='_'||*ctemp=='$'||isletter(*ctemp)||isadigit(*ctemp)){
			*ltemp++=*ctemp++;
		}
	}
	//check if Method
	if (*ctemp=='('){
		*token=Method;
		*ltemp=0;
		return ctemp;
	}
	else if (iswspace(*ctemp)||*ctemp==0||issymbol(*ctemp)){
		*ltemp=0;
		//check if constant identifier
		max=6;
		for (ctr=0;ctr<6;ctr++){
			if (!strcmp(constant[ctr],lexeme)){
				*token=Constant;
				*ltemp=0;
				return ctemp;
			}
		}
		//check if Operator
		max=27;
		for (ctr=0;ctr<6;ctr++){
			if (!strcmp(oprtr[ctr],lexeme)){
				*token=Operator;
				return ctemp;
			}
		}
		
		*token=Identifier;
		return ctemp;
	}
	
	*lexeme=0;
	return code;
}
//#include"next_comment.h"
char *nextDelimiter(char *code,char *lexeme,int *token){
	if (iswspace(*code)){
		if (*code==' '){
			strcpy(lexeme,"<space>");
		}	
		else if (*code=='\t'){
			strcpy(lexeme,"<tab>");
		}
		else if(*code=='\n'){
			strcpy(lexeme,"<\\n>");
		}
		*token=Delimiter;
		code++;
	}
	return code;
}

char *skipComments(char *code,char *lexeme,int *token){
	if (*code=='#'){
		while (*code!='\n'&&*code!=0){
			*code++;
		}
	}
	if (*code=='\''&&*(code+1)=='\''&&*(code+2)=='\''){
		code++;code++;code++;
		while (*code!='\''||*(code+1)!='\''||*(code+2)!='\''){
			if (*code==0){
				strcpy(lexeme,"<errcomment>");
				*token=Error;
			}
			code++;
		}
		code++;code++;code++;
	}
	
	return code;
}

char *nextLexical(char *code,char *lexeme,int *token){

	*token=-1;
	code=skipComments(code,lexeme,token);
	if (*token!=-1){
		return code;
	}
	code=nextDelimiter(code,lexeme,token);
	if (*token!=-1){
		return code;
	}
	code=nextNumber(code,lexeme,token);
	if (*token!=-1){
		return code;
	}
	code=nextString(code,lexeme,token);
	if (*token!=-1){
		return code;
	}
	code=nextSymbol(code,lexeme,token);
	if (*token!=-1){
		return code;
	}
	code=nextIdentifier(code,lexeme,token);
	if (*token!=-1){
		return code;
	}
	
	*lexeme=0;
	return code;
}

void analyse(char *code){
	char *lexeme=(char*)malloc(sizeof(char));
	int token,c;
	for (c=0;c<9;c++){
		token_count[c]=0;
	}
	printf("------------------------------------------------------\n");
	c=1;
	while (*code!=0)
	{
		code=nextLexical(code,lexeme,&token);
		token_count[token]++;
		printf("%d Token: %s\tLexeme: %s\n",c++,token_array[token],lexeme);
		//if (token==Error){break;}
	}
	printf("------------------------------------------------------\n");
	printf("Delimiter:\t%d\nNumber:\t\t%d\nString:\t\t%d\nSymbol:\t\t%d\nConstant:\t%d\nMethod:\t\t%d\nOperator:\t%d\nIdentifier:\t%d\nError:\t\t%d\n------------------------------------------------------\nTotal Token:\t%d",
		token_count[Delimiter],token_count[Number],token_count[String],token_count[Symbol],token_count[Constant],token_count[Method],token_count[Operator],token_count[Identifier],token_count[Error],
		token_count[Delimiter]+token_count[Number]+token_count[String]+token_count[Symbol]+token_count[Constant]+token_count[Method]+token_count[Operator]+token_count[Identifier]+token_count[Error]
	);
	printf("\n------------------------------------------------------\nAnalysis Done!");
}

int main(int a,char **args){
	char *code;
	//clrscr();
	
	if (a>=2){
		code=readFile(*(args+1));
		if (code!=NULL){
			printf("Lexical Analysis:\n");
			analyse(code);
			getch();
		}
		else{
			printf("Error: Could not find or load %s file\n",*(args+1));
		}
	}
	else{
		printf("Snap Lexical Analyzer [alpha version]\n(c) 2017 Rainbow Bulb Corporation. All rights reserved.\n\nEnter a code:\n");
		code=getcode();
		analyse(code);
		getch();
	}
	
	libre(code);
	return 0;
}
