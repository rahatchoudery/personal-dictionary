# personal_dictionary
This program compares words in a file against another file which holds 
a list of known words (a personal dictionary).

It starts by reading a file of text called p5dict.txt and storing each unique 
word in some node of a binary search tree. Next, it reads the words from a 
second data file and searches for them in the tree. If a word from the second 
file p5suspect.txt is found in the dictionary tree, it is treated as being 
correct and nothing more needs to be done. If a word from the second file is 
not found, two possibilities exist: either it is correctly spelled – in this 
case the program asks the user if this word should be inserted into the binary 
tree; if the user answers ‘y’ or ‘Y’, it is inserted in the dictionary; if the 
user answers ‘n’ or ‘N’, the word is considered to be mis-spelled and is printed 
out with a status message to that effect.
