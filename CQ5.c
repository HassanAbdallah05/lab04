#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void SIGNAL_HANDLER(int signal); 

int main(){

	signal(SIGINT , SIGNAL_HANDLER); 

	int ctr = 1; 	

	while(1){
		printf("%d :inside the main fucntion\n" , ctr);
	       	ctr++; 
		sleep(1); 	
	}


	return 0 ; 
}

void SIGNAL_HANDLER(int signal){
	printf("\ninside the handler function\n");
}
