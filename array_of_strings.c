/* array_of_strings.c:
     Example of using string and array of strings.
     Notes:
       - in this program string variables are NOT modified,
         that is, they are use as constants only,
         their value is initialized as declaration and remain unchanged
       - in reality, of cousre, string variables can be modified,
         but that need a bit more cautions as discussed in
         the lectures & workshops


    Anh Vo, anhvir@gmail.com, for unimelb COMP20005 workshop Week 8
*/


/* INTRODUCTION
1. A string is a sequence of characters, such as "ABC", "A1223", "Jun"
   which can be manipulated as a single object.
   We can use "char *" (same as "pointer to char") for string declaration.
   For printing a string we can use format "%s".

   Example:
   char *my_name= "Bob";   /* my_name is string of 3 characters */
   char *this_month= "April";
   char *this_day= "Mon";

   printf("My name is %s.\nToday is %s.\n",my_name, this_day);

   Notes: as this level, we only use string variable as constants.
   Remember to initialize strings as above. Note that the following 
   lines are WRONG:
   char *my_name;    
   my_name= "Bob";   /* WRONG, we cannot assign strings like that */ 
     
2. We can use and initialize an array of string like in example below:
   char *seasons[4]= {"Spring", "Summer", "Autumn", "Winter"};
   int this_season= 2;

   printf("This season is %s\n", seasons[ this_season ];

*/






