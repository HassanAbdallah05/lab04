#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


int main(){

	pid_t pid = fork() ;

	if(pid == 0 ){
		printf("Hello child\nPID: %d\nGroup ID: %d\n" , getpid(), getpgrp());
	       	pause(); 
	}else{
		sleep(3); 
		kill(pid , SIGKILL);  
	} 


	return 0 ; 
}
