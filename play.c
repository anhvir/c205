#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
    int a=0, b=0, c=0;    // variables for input data
    int x=0;              // variables for ... 
    int n= -100;

    // Step 1: input data 
    printf("PLAYING WITH FINDING SOME VALUE USING INPUTS\n\n");
    printf("Enter 3 real numbers: "); 

        
   
    n= scanf("%d %d %d", &a, &b, &c);


    /*  
        printf("Invalid input. Please try again.\n");
        exit( EXIT_FAILURE );
    }   
    */  
        
    // Output results 
    printf("We have a= %d, b= %d, c= %d\n", a, b, c); 
    printf("n= %d   x= %d\n", n, x); 

    printf("The min value is: "); 

    printf("\n\n");
    return 0;
}
