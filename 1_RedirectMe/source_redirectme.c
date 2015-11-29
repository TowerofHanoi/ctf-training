#include <stdio.h>
#include <stdlib.h>
 
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
void vulnerable_function(){
	int control=0;
	char very_long_buffer[10]; 
	printf("What's the magic word?\n");
	gets(very_long_buffer);
	return;
}
int main(){
	vulnerable_function();
	printf("Nope, wrong magic!");
	return 0;
}
