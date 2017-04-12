#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void gotoxy(int x,int y){
	COORD location={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),location);}
void bord(){
	float c;
	system("cls");
	for (c=0;c<160;c++) printf("%c",1); 
	for (c=0;c<22;c++){
		gotoxy(0,c);printf("%c%c",1,1);
		gotoxy(78,c);printf("%c%c",1,1);}
	for (c=0;c<160;c++) printf("%c",1);
}
void border(){	float c;
	system("cls");
	Sleep(50);
	for (c=0;c<160;c++) printf("%c",1); 
	Sleep(100);
	for (c=0;c<22;c++){
		gotoxy(0,c);printf("%c%c",1,1);
		gotoxy(78,c);printf("%c%c",1,1);
		Sleep(50);}
	for (c=0;c<160;c++) printf("%c",1);
	gotoxy(36,11);printf("WELCOME!");
	for (c=0.1;c<3.14*6;c+=0.1){
		gotoxy(cos(c)*7+40,sin(c)*4+11);
		printf("%c",1);
		Sleep(5);
		gotoxy(cos(c)*7+40,sin(c)*4+11);
		printf(" ");}
	gotoxy(36,11);printf("        ");
}
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

void average(){
	float a_g,a_sum=0;
	int a_c;
	
	gotoxy(30,3);
	printf("WELCOME TO AVERAGE!");
	for (a_c=0;a_c<5;a_c++){
	gotoxy(30,a_c+7);printf("Grade-%d:\t\t",a_c+1);scanf("%f",&a_g);
	a_sum+=a_g;}
	gotoxy(30,a_c+9);
	printf("Average:\t\t%0.2f",a_sum/5);
	
	getch();
}
void math(){
		float m_a=-3.14,m_b=9.8;
	int m_c=-4;
	
	gotoxy(20,3);printf("Mathematical Library Functions!");
	gotoxy(15,6);printf("number a:\t\t%0.2f",m_a);
	gotoxy(15,7);printf("number b:\t\t%0.2f",m_b);
	gotoxy(15,8);printf("number c:\t\t%d",m_c);
	
	gotoxy(15,10);printf("Absolute value of c:\t%d",              abs(m_c));
	gotoxy(15,11);printf("Absolute value of a:\t%0.2f",            fabs(m_a));
	gotoxy(15,12);printf("Ceil value of b:\t\t%0.2f",                ceil(m_b));
	gotoxy(15,13);printf("Floor value of b:\t%0.2f",              floor(m_b));
	gotoxy(15,14);printf("pow(%0.2f,%0.2f):\t\t%0.2f", 4.00,2.00,pow(16,0.5));
	gotoxy(15,15);printf("sqrt(%0.2f):\t\t%0.2f",          16.00,sqrt(16.00));
	gotoxy(15,16);printf("cosine %0.2f Pi:\t\t%0.2f",   0.50,cos(0.5*3.1415));
	gotoxy(15,17);printf("sine %0.2f Pi:\t\t%0.2f",     0.50,sin(0.5*3.1415));
	gotoxy(15,18);printf("tangent %0.2f Pi:\t\t%0.2f",   0.25,tan(0.25*3.1415));
	
	getch();
}
void fall(){char fa_name[50];
	int fa_x,fa_y,fa_ctr;
	
	gotoxy(25,3);printf("Welcome to falling asterisk!");
	gotoxy(25,6);printf("Enter your name:");
	gotoxy(25,7);gets(fa_name);
	
	for (fa_x=0;fa_x<strlen(fa_name);fa_x++){
		fa_ctr=1;
	for (fa_y=7;fa_y<18;fa_y++){
		gotoxy(fa_x+25,fa_y);printf("*");
		Sleep(500/(fa_ctr));
		gotoxy(fa_x+25,fa_y);printf(" ");
		Sleep(500/(fa_ctr++));
	}	
	gotoxy(fa_x+25,fa_y);printf("%c\a",fa_name[fa_x]);
	}
	
	getch();
}
void second(){
	int t_s,t_m,t_h;

	gotoxy(30,3);printf("WELCOME TO SECONDS!");
	gotoxy(25,8);printf("  Enter second/s:\t");scanf("%d",&t_s);
	
	gotoxy(30,11);printf("hour/s:\t\t%d",t_s/3600);
	gotoxy(30,12);printf("minute/s:\t\t%d",t_s%3600/60);
	gotoxy(30,13);printf("second/s:\t\t%d",t_s%60);
	
	getch();
}
void bubble(){int c,k;float grade[10];
	gotoxy(30,3);printf("WELCOME TO BUBBLE SORT!");
	gotoxy(10,7);printf("Enter your 10 grade/s:");
	for (c=0;c<10;c++){
	gotoxy(20,c+8);
	scanf("%f",&grade[c]);}
	for (c=0;c<9;c++){
	for (k=0;k<9-c;k++){
	if (grade[k]>grade[k+1]){
	grade[k]+=grade[k+1];
	grade[k+1]=grade[k]-grade[k+1];
	grade[k]-=grade[k+1];}}}
	gotoxy(40,7);printf("Your grade/s in ascending order:");
	for (c=0;c<10;c++) {
	gotoxy(50,c+8);
	printf("%0.2f",grade[c]);
}
getch();	
}
void hungman(){
	int hm_c;
	char hm_com[25],hm_ans[25],hm[50][21]={
	"computer","laptop","cellphone","mouse","keyboard","monitor","printer","scanner","telephone","television",
	"radio","facebook","instagram","google","twitter","skype","yahoo","viber","internet","microsoft",
	"monkey","dolphine","ostrich","horse","chicken","flying fish","donkey","elephant","zebra","carabao",
	"galaxy","planet","nebula","star","universe","asteroid","comet","cloud","black hole","space",
	"one piece","naruto","dragon ball","fairy tail","full metal alchemist","attack on titan","bleach","slamdunk","kuroko no basket","hunter x hunter"};
	
	srand(time(NULL));
	strcpy(hm_com,hm[rand()%50]);
	char hm_fin[strlen(hm_com)];
	
	for (hm_c=0;hm_c<strlen(hm_com);hm_c++) hm_fin[hm_c]='*';
	for (hm_c=strlen(hm_com);hm_c<25;hm_c++) hm_fin[hm_c]='\0';
	do{
		bord();
		gotoxy(30,3);printf("Welcome to HungMan Game!");
		gotoxy(38,8);printf("%s",hm_fin);
		gotoxy(20,10);printf("Enter a word or letter to guess the word: ");
		gets(hm_ans);
		
		if (strcmp(hm_ans,hm_com)==0) strcpy(hm_fin,hm_ans);
		else for (hm_c=0;hm_c<strlen(hm_com);hm_c++) 
			if (hm_ans[0]==hm_com[hm_c]) hm_fin[hm_c]=hm_ans[0];
	}while (strcmp(hm_fin,hm_com)!=0);

bord();
gotoxy(30,3);printf("Welcome to HungMan Game!");
gotoxy(38,8);printf("%s",hm_fin);
gotoxy(25,10);printf("Congratulations you guessed the word!\a");

getch();
}
void rock(){
	int com,you,opp=0,score=0,high_score=0;
	char bet[3][8]={"ROCK","PAPER","SCISOOR"},ans;
	srand(time(NULL));
	do{
	score=0;opp=0;
	do{
		bord();
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
	Sleep(1000);
	}while (opp==0);
	gotoxy(32,18);printf("Repeat[y/n]:\t");ans=getche();
}while (ans=='y'||ans=='Y');
}
void number(){int dec,rem[100],c=0,m;
	gotoxy(25,3);printf("WELCOME TO NUMBER SYSTEM");
	gotoxy(25,7);printf("DECIMAL:\t\t");scanf("%d",&dec);
	int bin=dec,oct=dec,hex=dec;
	
	
	gotoxy(25,9);printf("BINARY:\t\t");//start binary
	while (bin!=0){
		rem[c++]=bin%2;
		bin/=2;}
	m=c-1;
	for (c=m;c>=0;c--) printf("%d",rem[c]);//end binary
	
	gotoxy(25,10);printf("GRAYCODE:\t\t%d",rem[m]);//start graycode
	for (c=m-1;c>=0;c--) printf("%d",rem[c+1]^rem[c]);//end graycode
	
	gotoxy(25,11);printf("1's COMPLIMENT:\t");//start 1's compliment
	for (c=m;c>=0;c--) {
	rem[c]=rem[c]==0? 1:0;
	printf("%d",rem[c]);}//end 1's compliment
	
	gotoxy(25,12);printf("2's COMPLIMENT:\t");//start 2's compliment
	rem[0]++;
	for (c=1;c<=m;c++) if (rem[c-1]==2){
	rem[c]++;rem[c-1]=0;}
	for (c=m;c>=0;c--) printf("%d",rem[c]);//end 2's compliment
	
	gotoxy(25,13);printf("OCTAL:\t\t\t");//start octal
	while (oct!=0){
	rem[++c]=oct%8;
	oct/=8;}
	for (c;c>=0;c--) printf("%d",rem[c]);//end octal
	
	char kar;
	gotoxy(25,14);printf("HEXADECIMAL:\t\t");
	while (hex!=0){
		rem[++c]=hex%16;
		hex/=16;}
	for (c;c>=0;c--){
		if (rem[c]>=10){
		kar='A';
		for (hex=10;hex<rem[c];hex++) kar++;printf("%c",kar);}
		else printf("%d",rem[c]);}
		
getch();	
}
void exit(){
	int c;
	char thanks[20]="THANKS FOR VIEWING!",written[12]="Written by:",marz[13]="Marion Owera",ang[17]="Angelo Gutierrez",
	sub[]="Submitted to:",mam[]="Ma'am Guevarra";
	
	gotoxy(30,6);for (c=0;c<strlen(thanks);c++){Sleep(100);printf("%c",thanks[c]);}
	gotoxy(40,13);for (c=0;c<strlen(written);c++){Sleep(100);printf("%c",written[c]);}
	gotoxy(45,14);for (c=0;c<strlen(marz);c++){Sleep(100);printf("%c",marz[c]);}
	gotoxy(45,15);for (c=0;c<strlen(ang);c++){Sleep(100);printf("%c",ang[c]);}
	gotoxy(40,17);for (c=0;c<strlen(sub);c++){Sleep(100);printf("%c",sub[c]);}
	gotoxy(45,18);for (c=0;c<strlen(mam);c++){Sleep(100);printf("%c",mam[c]);}
}

//MAIN FUNCTION
int main(){
	int c;
	char choice;
	system("color 3e");
	
	do{
	border();
	menu();
	
	Sleep(50);gotoxy(15,12);
	printf("0.Random");
	Sleep(50);gotoxy(15,13);
	printf("1.Average");
	Sleep(50);gotoxy(15,14);
	printf("2.Math library");
	Sleep(50);gotoxy(15,15);
	printf("3.Falling Asterisk");
	Sleep(50);gotoxy(15,16);
	printf("4.Seconds");
	Sleep(50);gotoxy(45,12);
	printf("5.Bubble sort");
	Sleep(50);gotoxy(45,13);
	printf("6.HungMan");
	Sleep(50);gotoxy(45,14);
	printf("7.Rock Paper Scissor");
	Sleep(50);gotoxy(45,15);
	printf("8.Number System");
	Sleep(50);gotoxy(45,16);
	printf("9.Exit");
	Sleep(50);gotoxy(30,19);
	printf("Choose:\t");
	choice=getche();
	
	if (choice=='0'){srand(time(NULL)); for (c=0;c<rand()%9+1;c++) choice++;}
	border();
	switch (choice){
		case '1':average();break;
		case '2':math();break;
		case '3':fall();break;
		case '4':second();break;
		case '5':bubble();break;
		case '6':hungman();break;
		case '7':rock();break;
		case '8':number();break;
		case '9':exit();break;
		default :gotoxy(35,10);printf("Invalid Input!");Sleep(500);}
	}while (choice!='9');
getch();
}
