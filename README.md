The Get Next Line project from 42 School !

The goal of this program is to read from a file or the standard entry and return the content line by line until it reaches the end of the file.

How it works :
- As long as the end of the file has not been reached and our static variable doesn't contain a \n, we read from the file and keep the text we read in our static variable ;
- Once our static variable contains a \n, we exit the reading loop to enter one of two condition : either there's text after the \n, or the \n is the last thing in the string.
- If there is a remainder in our static variable, we extract the first part of our static variable and store the rest ;
- If not, we simply return our current line.

And that's it ! The challenge resides mainly in the dynamic memory allocation, so make sure to free everything you malloc, including in your malloc projection - for instance, if your third malloc fails, you must free everything your have created so far.

Good luck with your own get_next_line :)

‧₊˚ ☁️⋅♡𓂃 ࣪ ִֶָ☾.
