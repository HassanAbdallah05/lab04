// working of setjmp() and longjmp() 

#include <setjmp.h> 
#include <stdio.h> 

jmp_buf buf; 

void func() 
{ 
    printf("Welcome CS223\n"); 
  
    // Jump to the point setup by setjmp 
    longjmp(buf, 1); 
  
    printf("Hello2\n"); 
} 
  
int main() 
{ 
    // Setup jump position using buf and return 0 
    
    if (setjmp(buf)) 
        printf("Hello3\n"); 
    else { 
        printf("Hello4\n"); 
        func(); 
    } 
    return 0; 
}