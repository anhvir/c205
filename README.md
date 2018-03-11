 c205 Week 03:
=======

  * **guessNumber.c** is the same as it was last week. If you run it, and enter your FULL NAME (ie 2 or more words) the program crashed! Reason: **scanf("%s", name)** is naughty, when we enter **John Smith** it will only get **John** for **name** (ie stops at first whitespace), and leave **Smith** in the buffer. That **Smith** will be read by the next **scanf** which, unfortunately, is looking for a *numeric* entry.

  * Your duty is to change **scanf("%s", name)** so that it behave better (accepting whitespaces). You can ask our friend Google, or you can ask your frieds, including Anh. 

  * e2x.c is program to compute:

    S=    1 + x/1! + x/2! + ... + x^n/n! + ...

but, of course, not until infinity, just until the first value n that make **| x^n/n! |  < 1e-6 **, ie to the precision of 1e-6. Explore the program, learn a bit about the **while** loop and using **#define#**. Change the program so that:
     ** the precison become 1e-9
     ** also output the number of steps the **while** loop executed.     
 
-------------------------------------------------------------
by anhvir@gmail.com, for use in unimelb COMP20005 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.
