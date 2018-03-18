/* Anh Vo, anhvir@gmail.com, for unimelb.COMP20005.Workshop.Week4 */

/* This program asks your name, greets you, and then
	asks you to guess a number from 0 to 6,
	the program will terminate only after you give
	the right guess
   NOTE: this topic is not important, you can skip if having no time
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10	
#define MY_NAME "Anh"
#define MAX_NAME_LEN 50

int main(int argc, char *argv[]) {
	int answer,	
		guess,		
		count= 0;
	char name[MAX_NAME_LEN + 1];		
	
	/* greeting */ 
	printf("Hi! My name's %s. \nWhat's your name? ", MY_NAME);
	if (scanf("%[^\n]", name) != 1) {
       printf("Please enter your name!\n");
       exit(EXIT_FAILURE);
    }
        /* here, "%[^,]" means "get anything until first see \n
                                and do not include that \n into the read data"
        */
        /* There are, of course, other ways to do 
           but that's out of our story  
        */
        /* FINAL NOTE: it is supposed that the input
                       name has less than MAX_NAME_LEN charaters
           WHY: (not so important for us at this stage)
        */
           

    /* no change made to the rest of this file */
	printf("\nGreat, %s! Very nice to meet you!\n\n", name);
	
	/* get secret answer as a random number */
	srand(time(NULL)); 
	answer= rand() % MAX; 
	
	printf("Now, let's start a game\n"
			"I have in my mind a secret number  between 0 and %d,\n"
			"you have to guess that number.\n"
			"The game will end after you give a correct guess!\n\n",
			MAX-1 );
	/* loop to receive guesses */
	guess = -1; 
	while (guess != answer) {
		printf ("Make a guess = ");
		scanf("%d", &guess);
		count= count + 1;
	}
	
	/* print results */
	printf("\nYou've got the right answer after %d guesses.\n", count);
	if (count <= MAX/2) {
		printf ("You were so smart!\n");
	} else if (count < MAX) {
		printf ("You did well!\n");
	} else {
		printf ("Not bad!\n");
	}
	
	printf("\nHope that you enjoyed it. See you!\n\n");
	
	return 0;
}

		
	
