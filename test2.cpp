#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	pid_t pid;
	pid = fork();
	printf("fork test");
	sleep(10);
	exit(0);
}
