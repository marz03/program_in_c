#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
/*Main style*/
void gotoxy(int x,int y){
	COORD location={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),location);}

void spin(){
	for (int k=1;k<=10;k++){
	for (float c=0.1;c<=6.283;c+=0.1){
		gotoxy(cos(c)*(k+29)+40,sin(c)*(k+1)+12);printf("%c",2);
		Sleep(1);}
	k++;}}	

void border(){	
	int c;
	system("cls");
	for (c=0;c<160;c++) printf("%c",1); 
	for (c=0;c<22;c++){
		gotoxy(0,c);printf("%c%c",1,1);
		gotoxy(78,c);printf("%c%c",1,1);}
	for (c=0;c<160;c++) printf("%c",1);
}

void start(){
	char a[]="WELCOME",b[]="TO GAME COLLECTIONS";
	int c;
	system("color b");
	border();
	spin();
	for (c=0;c<strlen(a);c++){
		gotoxy(c+35,11);printf("%c",a[c]);
		Sleep(50);
	}
	for (c=0;c<strlen(b);c++){
		gotoxy(c+30,12);printf("%c",b[c]);
		Sleep(50);
	}
	Sleep(500);
	system("cls");
	border();}

void menu(){
	gotoxy(9,3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
	gotoxy(9,4);
	printf("%c%c%c%c%c%c%c%c%c%c   %c%c%c%c   %c%c      %c%c   %c%c%c%c  %c%c  %c%c  %c%c  %c%c%c%c%c%c%c%c%c\n"
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1      ,1,1,1,1      ,1,1            ,1,1      ,1,1,1,1    ,1,1    ,1,1    ,1,1    ,1,1,1,1,1);
	gotoxy(9,5);
	printf("%c%c%c%c%c%c%c%c%c%c          %c%c  %c%c%c%c%c%c    %c%c%c  %c%c  %c%c  %c%c  %c%c%c%c%c%c%c%c%c\n"
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
	gotoxy(9,6);
	printf("%c%c%c%c%c%c%c%c%c%c  %c%c  %c%c  %c%c      %c%c  %c  %c%c  %c%c  %c%c  %c%c  %c%c%c%c%c%c%c%c%c\n"
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
	gotoxy(9,7);
	printf("%c%c%c%c%c%c%c%c%c%c  %c%c  %c%c  %c%c  %c%c%c%c%c%c  %c%c  %c  %c%c  %c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c\n"
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
	gotoxy(9,8);
	printf("%c%c%c%c%c%c%c%c%c%c  %c%c  %c%c  %c%c      %c%c  %c%c%c    %c%c      %c%c  %c%c%c%c%c%c%c%c%c\n"
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
	gotoxy(9,9);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
}

/*end Main style*/
/*list of game*/
void hungman();
void rps();
void ttt();
void fial();
void exit();
/*end list of game*/
/*ttt*/
void box();
void user(int *ur,int *h,int *ch);
void comp(int *cp,int *h,int *ch);
void check(int *ch,int *b,int *h);
/*end ttt*/

main(){
	system("title My Games");
	int i;
	srand(time(NULL));
	
	start();
	do	{
	system("cls");
	border();
	menu();	
	
	Sleep(50);gotoxy(30,12);printf("0.RANDOM");
	Sleep(50);gotoxy(30,13);printf("1.HUNGMAN");
	Sleep(50);gotoxy(30,14);printf("2.ROCK PAPER SCISSOR");
	Sleep(50);gotoxy(30,15);printf("3.TIC-TAC-TOE");
	Sleep(50);gotoxy(30,16);printf("4.FOUR IN A LINE");
	Sleep(50);gotoxy(30,17);printf("5.EXIT");
	Sleep(50);gotoxy(30,19);printf("CHOOSE:\t");
	scanf("%d",&i);
	
	if (i==0) i=rand()%5+1;
	switch (i){
		case 1:hungman();break;
		case 2:rps();break;
		case 3:ttt();break;
		case 5:exit();break;
	}
	
	}while (i!=5);	


system("cls");
}

void hungman(){
	int c,score=0,life=10,hint=5;
	char pos[51][50]={"computer","laptop","cellphone","mouse","keyboard","monitor","printer","scanner","telephone","television",
	"radio","facebook","instagram","google","twitter","skype","yahoo","viber","internet","microsoft",
	"monkey","dolphine","ostrich","horse","chicken","flying fish","donkey","elephant","zebra","carabao",
	"galaxy","planet","nebula","star","universe","asteroid","comet","cloud","black hole","space",
	"one piece","naruto","dragon ball","fairy tail","full metal alchemist","attack on titan","bleach","slamdunk","kuroko no basket","hunter x hunter","\0"};
	char fin[50],ans[50]="yes",com[50],prev[50],name[50];
	border();
	//welcome
	char wel[]="WELCOME TO HUNGMAN GAME!";	
	gotoxy(30,4);for (c=0;c<strlen(wel);c++){
	Sleep(20);printf("%c",wel[c]);}
	gotoxy(7,7);printf("Enter your name:\t");gets(name);gets(name);
	//outer loop
	while (strcmp(ans,"yes")==0){
	strcpy(com,pos[rand()%51]);
	if (strcmp(com,"\0")==0) strcpy(com,name);
	strupr(com);
	for (c=0;c<strlen(com);c++) if (com[c]!=' ') fin[c]='*';
	for (c=strlen(com);c<=50;c++) fin[c]='\0';
	life=10;
	//inner loop
	while (life!=0){
	border();
	gotoxy(3,3);puts(name);
	gotoxy(23,5);printf("HINT:\t%d",hint);
	gotoxy(23,6);printf("LIFE:\t%d",life);
	gotoxy(23,7);printf("SCORE:\t%d",score);
	gotoxy(23,9);puts(fin);
	gotoxy(23,11);
	printf("Enter a letter or word to guess the word:");
	gotoxy(35,13);
	gets(ans);strupr(ans);
	
	strcpy(prev,fin);
	if (strcmp(ans,"HINT")==0&&hint>0){while (strcmp(prev,fin)==0){
		c=rand()%strlen(com);
		fin[c]=com[c];}
		hint--;}
	if (strcmp(ans,com)==0) strcpy(fin,com);
	else
	for (c=0;c<strlen(com);c++) 
	if (ans[0]==com[c]) fin[c]=com[c];
	if (strcmp(prev,fin)==0) life--;
	if (strcmp(fin,com)==0) break;}
border();
gotoxy(3,3);puts(name);
gotoxy(23,5);printf("HINT:\t%d",hint);
gotoxy(23,6);printf("LIFE:\t%d",life);
gotoxy(23,7);printf("SCORE:\t%d",score);
gotoxy(23,9);puts(com);
gotoxy(23,11);
if (life==0) printf("You lose!");
else {score++;hint++;printf("Congratulations you've guessed the word!\a");
gotoxy(30,16);printf("Repeat: ");gets(ans);
strlwr(ans);}
}
getch();
}

void rps(){
	int com,you,opp=0,score=0,high_score=0;
	char bet[3][8]={"ROCK","PAPER","SCISOOR"},ans;
	srand(time(NULL));
	do{
	score=0;opp=0;
	do{
		border();
		gotoxy(25,3);printf("WELCOME TO ROCK,PAPER,SCISSOR GAME");
		gotoxy(30,6);printf("High Score: %d",high_score);
		gotoxy(30,7);printf("Sore:       %d",score);
		gotoxy(30,8);printf("1.ROCK");
		gotoxy(30,9);printf("2.PAPER");
		gotoxy(30,10);printf("3.SCISSOR");
		gotoxy(30,12);printf("Enter your bet: ");scanf("%d",&you);
		if (you>3||you<1) {gotoxy(30,13);printf("Invalid Input!");}
		else {
			com=rand()%3+1;
			gotoxy(13,14);printf("Your bet!\t%s    \t%s    \tComputer bet!",bet[you-1],bet[com-1]);
			gotoxy(32,16);
			if (you==com) printf("tied!");
			else if (you==1&&com==3){
				printf("You won!");score++;}
  			else if (you==3&&com==1){
				printf("Computer win!");opp++;}
			else if (you>com){
				printf("You won!");score++;}
			else{
				printf("Computer won!");opp++;}
		}
	high_score= score>high_score? score:high_score;
	Sleep(3000);
	}while (opp==0);
	gotoxy(32,18);printf("Repeat[y/n]:\t");ans=getche();
}while (ans=='y'||ans=='Y');

}

void ttt(){
	system("cls");
	border();
	int b=0,ur[100],cp[20],h[20],c=0;
	for (int k=0;k<9;k++) h[k]=NULL;
	box();
	
	do{
	user(ur+c,&h[c],h);
	check(ur,&b,h);
	if (b==3){
	gotoxy(50,10);printf("YOU WON!");
	break;}
	else if (b==9){
		gotoxy(50,10);printf("YOU TIED!");
		break;}
	comp(cp+c,&h[c+1],h);
	check(cp,&b,h);
	if (b==3) {
	gotoxy(50,10);printf("COMPUTER WON!");
	break;}
	else if (b==9){
		gotoxy(50,10);printf("YOU TIED!");
		break;}
	c+=2;
	}while (b==0);
	
getch();
}

/*ttt*/
void box(){
	for (int c=0;c<9;c++){
		gotoxy((c%3)*9+15,c/3*5+5);printf("%d",c+1);
	}
}

void user(int *ur,int *h,int *ch){
	int t,c,b=0;
	gotoxy(45,5);printf("Enter a slot:");
	do{
	b=0;
	gotoxy(65,5);printf("             ");
	gotoxy(65,5);scanf("%d",&t);
	
	if (t<1||t>9) b++;
	else
	for (c=0;c<10;c++)
	if (ch[c]==t) b++;
	if (b==0){
		gotoxy(((t-1)%3)*9+15,(t-1)/3*5+5);printf("X");
		*h=t;
		*ur=t;}
	else {gotoxy(30,20);printf("Invalid Input!");
	Sleep(1000);gotoxy(30,20);printf("              ");}
}while (b!=0);
}

void comp(int *cp,int *h,int *ch){
	int t,c,b=1;
	srand(time(NULL));
	while(b!=0){
	b=0;
	t=rand()%9+1;
	if (t<1||t>9) b++;
	else
	for (c=0;c<10;c++)
	if (ch[c]==t) b++;
	if (b==0){
		gotoxy(45,7);printf("Computer choice:\t%d",t);Sleep(1000);
		gotoxy(45,7);printf("                \t ");
		gotoxy(((t-1)%3)*9+15,(t-1)/3*5+5);printf("O");
		*h=t;
		*cp=t;}
	}
}

void check(int *ch,int *b,int *h){
	int t,c;
	for (c=0,t=0;c<9;c++)	if(ch[c]>=1&&ch[c]<=3) t++;		if (t==3) *b=3; 
	for (c=0,t=0;c<9;c++)  	if(ch[c]>=4&&ch[c]<=6) t++;		if (t==3) *b=3; 
	for (c=0,t=0;c<9;c++)  	if(ch[c]>=7&&ch[c]<=9) t++;		if (t==3) *b=3; 
	for (c=0,t=0;c<9;c++)  	if(ch[c]==1||ch[c]==4||ch[c]==7) t++;		if (t==3) *b=3; 
	for (c=0,t=0;c<9;c++)  	if(ch[c]==2||ch[c]==5||ch[c]==8) t++;		if (t==3) *b=3; 
	for (c=0,t=0;c<9;c++)  	if(ch[c]==3||ch[c]==6||ch[c]==9) t++;		if (t==3) *b=3; 
	for (c=0,t=0;c<9;c++)  	if(ch[c]==1||ch[c]==5||ch[c]==9) t++;		if (t==3) *b=3; 
	for (c=0,t=0;c<9;c++)  	if(ch[c]==3||ch[c]==5||ch[c]==7) t++;		if (t==3) *b=3; 
	if (*b!=3)	for (c=0,t=0;c<9;c++)	if (h[c]!=NULL) t++;	if (t==9) *b=9;
	
}
/*end ttt*/

void exit(){
	system("cls");
	border();
	char str[]="THANK'S FOR YOUR PARTICIPATING!";
	srand(time(NULL));
	gotoxy(25,10);
	for (int c=0;c<strlen(str);c++){
	printf("%c",str[c]);Sleep(100);}
	gotoxy(25,10);
	for (int c=0;c<strlen(str);c++){
	printf(" ");Sleep(100);}
	for (int c=0;c<1000;c++){
	gotoxy(rand()%74+3,rand()%21+2);printf("%c",1);
	Sleep(5);}
	system("cls");
}
