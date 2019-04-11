 c205 Week 07:
=======

Today's task: Learn how to submit your assignment. You should build a 
very simple program and make sure that you can submit it. If possible,
finish Stage 1 today.

Additional files:
---------------- 

  * `ass1_notes.pdf` : 
Notes and advices on assignments 1, including the submission process.

  * `array.c` :
Simple examples on using arrays, can be used as skeleton for exercises 7.3 and 7.4.

  * `structs.c and students.txt`: **Warning:** This is an example of using
structs and arrays of structs. You do **not** need to use structs 
to complete your assignment, **no rewards** for attempting structs.
However, if you use, your program will be simpler and better. If
you think you want to use structs, you can read the textbook
chapter on structs, and have a look at `structs.c`.

`structs.c` a simple program and data for reading and storing a list of student records.
For simplicity, each student record has only 3 component: student ID, ATAR score, and year of entering the university.

After compiling, you can run the program with:

`./structs < students.txt`

in this case the program will run with data read from the file `students.txt` instead of from the keyboard. You also can do:

`./structs < students.txt > structs.out`

in this case, the output will be written to the file `structs.out` instead of to the computer's display.


------------------------------------------------------
HOWTO download this repository to your computer:

If you just want a single file, say, `prog.c`:
  * Click on `prog.c` and you will see its content 
  * Copy the content and paste into your jEdit/editor window, then save it in your working folder

If you want to download the whole directory:
  * Download this whole directory by clicking `Clone or Download` --> `Download ZIP`, it will normally be downloaded to your `Downloads` folder under the name `c205-master` or `c205-master.ZIP`
  * Then copy or move the folder `c205-master` from `Downloads` to under your working folder
  * If the downloaded `c205-master` has the extension `.ZIP`, you likely need to expand the zipped file with command `unzip c205-master.ZIP`. If the command doesn't work, ask Google how to unzip.
 
-------------------------------------------------------------
by anhvir@gmail.com, for use in unimelb COMP20005 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.
