The Get Next Line project from 42 School !

The goal of this program is to read from a file or the standard entry and return the content line by line until it reaches the end of the file.

Lessons learned
-
- Never malloc a static variable ; it's bad practice !
- If you have to malloc anything, it's best to free it as soon as possible ;
- Rewriting code allows one to really understand what is going on ;
- When developping an algorithm, one can use a diagram to visualize the flow and the conditions. 

Main Branch
-
> How it works :
- As we enter the function, we check wether we have some leftover from a previous read in our static char; if we do, we simply copy it in a dynamic string (*buff) and clear the leftovers so it's ready to be used again.
- We then read from the file as long as the end of the file hasn't been reached and *buff doesn't contain a \n, we join *buff with what we're reading from the file;
- Once buff contains a \n, we exit the reading loop to enter one of two condition : either there's text after the \n, or the \n is the last thing in the string.
- If there is a remainder in our static variable, we extract the first part of our static variable and store the rest in our static char, then return the line;
- If not, we simply return our line.

Deprecated GNL Branch
-
!! This code has a built-in leak because I mallocked the static variable. 
For a secure code that will not leak even if the program is forced to stop before the end of the file, see the main branch.

> How it works :
- As long as the end of the file hasn't been reached and the static variable doesn't contain a \n, we read from the file and keep the text we read in our static variable ;
- Once our static variable contains a \n, we exit the reading loop to enter one of two condition : either there's text after the \n, or the \n is the last thing in the string.
- If there is a remainder in our static variable, we extract the first part of our static variable and store the rest ;
- If not, we simply return our current line.

Good luck with your own get_next_line :)

‧₊˚ ☁️⋅♡𓂃 ࣪ ִֶָ☾.
