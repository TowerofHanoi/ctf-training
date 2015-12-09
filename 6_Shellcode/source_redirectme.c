#include <stdio.h>
#include <stdlib.h>
 
void vulnerable_function(){
	int control=0;
	char very_long_buffer[300]; 
	//In the future we will see how to leak addersses without this
	printf("the buffer is at \n%p\n", very_long_buffer); 
	printf("What's the magic word?\n");
	fflush(stdout);
	gets(very_long_buffer);
	return;
}
int main(){
	vulnerable_function();
	printf("Nope, wrong magic!");
	fflush(stdout);
	return 0;
}
