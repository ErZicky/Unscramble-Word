# Unscramble-Word
A simple c++ script to resolve scrambled words in english

The system makes use of the conversion char -> int of c++ to makes the comparison and deduce the word.

The system makes use of an english dictionary (named dictionary.txt).

## Note:
* Sometimes some scrambled words might be picked up as other words that came up first for example: inserting "rca" to find "car" will instead output again "rca" as is a word in the dictionary

* While the script is intended to work with the english dictionary could in theory work with other language as well but keep in mind that anything that any letter that isn't ASCII will break it so make sure to remove them from the dictionary or modify the script to accept other form of encoding

