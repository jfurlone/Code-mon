****************************************************
John M Furlone		0661197
CIS2750		  	A4
November 19th 2013
****************************************************

************
Compilation
************
To compile the program, type 'make' into the terminal.
For testing of the wrappers and c code type 'make testMain'
For testing of the lexx and yacc type 'make testYacc'

***********************
Running the program(s)
***********************
To run the java program type 'make run'

*****************
Known Limitations
*****************
Labels must be named prior to being used.

Logic errors when parsing (e.g. JMP with immediate mode, not enough number fields) do not stop parsing. Instead they send a message to stout.
Normal syntax errors and other errors normally caught by yyerror work though.

Cannot have a Trainer with a '-' character in their name.
Causes database parsing error for results.

*******************************
Academic Integrity Pledge
*******************************

I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased.  Furthermore,
I certify that this assignment was prepared by me specifically for this course.