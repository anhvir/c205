/*
  e2x.c : compute e^x to the precision of EPSILON= 1e-6,
          NOT using the library function exp(),
          NOT using library math functions at all
  
  Anh Vo, anhvir@gmail.com, for comp20005 unimelb
*/

/* DESIGN THOUGHTS:
We need to compute S= 1 + x + x^2/2! + x^3/3! + ...
We cannot just use one one assignment for that, right?
But we can:
   - Start with, say, S= 0 
   - add up one (appropriate) member, say p, to S
How about:
   - fisrt set p = 1, then p is the first member
   - set S= p       , the the first member is accumulated to S
and then we can REPEAT the following process:
   - change p so that the new p equal to the next member
   - add p to S

We refine and detail our above thought as follows:
   p= 1;    // first member
   S= 1;    // now S includes first member
   loop:    // NOT forever, but stop when |p| < EPSILON
      p=  (next member)   (***)
      S= S + p;    // accumulate p to S
   endloop
   output S     

Great! For the loop we can use the "while" statement.
The only problem is (***). Look at the expression of S, when
we move, say from p= x^2/2! to the next_p= x^3/3! we need
just to multiply p with x/3, that is, next_p= p * x /3.

How can we have that 3? Now, look at the whole C program below
(There are some notes at the end of this file, don't ignore them)
*/



#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-6

int main(int argc, char *argv[]) {
    float s=0, x, p;
    int i;
    
    // Part 1: input data
    printf("Computing e^x. Enter value for x: ");
    if ( scanf("%f",&x) != 1 ) {
        printf("Please rerun and enter a real number such as 1.2\n");
        exit(EXIT_FAILURE);
    }
 
    // Part 2: process computing s= e^x
    i= 0;
    p= 1;   // now i=0 and the i-th member is x^0/0! ie 1
    s= p;
    while ( p > EPSILON || p < -EPSILON ) {  // why so complicated?
        i= i+ 1;         // goto next member
        p= p * x / i;    // check in your paper if this's correct
        s= s+p;          // add i-th elements to S
    }   
        
    // Part 3: output result
    printf("EPSILON= %f, e_to_x = %.6f\n", EPSILON, s);
    
    return 0;
}

/* QUESTIONS:
  1. Because I did add p at S in line 65, is that better
     to delete line 61?
  2. Can I swap the order of lines 63-65?
  3. When designing, I used S, why did I used s instead in the C program?
  4. Change program so that the precision become 1e-9 instead of 1e-6.
     (warning: you need to make change in more than one places!)
  5. Change the program so that it also outputs the number of time
     the while loop executed.
  6. The condition:
        p > EPSILON || p < -EPSILON 
     is probably longer than needed:
       4a) can we just write p > EPSILON ?
       4b) is there anyway to simplify that condition? 
*/   


  
