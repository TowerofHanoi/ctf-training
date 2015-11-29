#include <stdio.h>
#include <stdlib.h>
 
void interactive_function(){
	char buffer[10]; 
	printf("Yes or nope?\n");
	fflush(stdout);
	fgets(buffer,9,stdin);
	if(buffer[0]=='y' || buffer[0]=='Y')
	{
		printf("you are positive!\nPlease input your name:\n");
		fflush(stdout);
		fgets(buffer,9,stdin);
		printf("Hello %s\n",buffer);
		printf("How are you today?\n");
		fflush(stdout);
		fgets(buffer,9,stdin);
		printf("You are indeed!");
	}else{
		printf("you are negative!\n");
		fflush(stdout);
	}


	return;
}
int main(){
	interactive_function();
	return 0;
}
