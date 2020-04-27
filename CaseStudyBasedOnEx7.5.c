/* Ex 7.5
Suppose that a set of "student number, mark" pairs are provided,
one pair of numbers per line, with the lines in no particular order.
Write a program that reads this data and outputs the same data, 
but ordered by student number. For example:
  stud   mark
823678  66
765876  94
864876  48
785671  68
854565  89
On this input your program should output:

Enter as many as 1000 "studnum mark" pairs, ^D to end
5 pairs read into arrays
studnum  mark
765876  94
785671  68
823678  66
854565  89
864876  48

------------------------
In this Case Study:
  + using typedef
  + using struct
  + recall: using selection sort
  + recall: usng redirection
------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

