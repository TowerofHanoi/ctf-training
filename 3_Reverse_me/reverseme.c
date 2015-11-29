#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int control;
void print_flag()
{
	char *name[] = {
        "/bin/sh",
        "-c",
        "cat flag",
        NULL
    };
    execvp(name[0], name);
}

void secure_funct(){
	char buffer2[100];
	char buffer[240];
	int i =0;
	printf("Enter the key\n");
	fgets(buffer,230,stdin);
	for(;i<230 && buffer[i]!='\0';i++){
		buffer[i]=buffer[i]+1;
	}
	printf(buffer);
	if(control){
		printf("Enter the second key:");
		gets(buffer2);
	}
}

int main(){
	secure_funct();
	int lol;
	if(lol==0){
		print_flag();
	}
	return 0;
}
