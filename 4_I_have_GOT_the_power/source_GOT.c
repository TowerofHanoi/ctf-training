#include <stdio.h>
#include <stdlib.h>
int control; 
void print_flag()
{
	char ch;
	FILE *fp;
	fp = fopen("flag","r"); 
	if( fp == NULL )
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	while( ( ch = fgetc(fp) ) != EOF )
		printf("%c",ch);
	fclose(fp);
}
void secure_echo(){
	char buffer[256];
	printf("Enter the message to echo\n");
	fgets(buffer,250,stdin);
	printf(buffer);
	printf("Did you like the echo?\n");
	fgets(buffer,4,stdin);
	if(buffer[0]=='y'){
		printf("Happy to hear that");
	}else{
		printf("Well, i don't give a fudge anyways");
	}
}
	
int main(){
	secure_echo();
	return 0;
}
