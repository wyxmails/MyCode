/*
Given a file input.txt, the data format is:
word1 1
word2 1
word1 3
word3 2
word4 5
word2 3
the first column means a word, the second column means the appear times of this word,
merge and count the words' appear times, the output of the above should be:
word1 4
word2 4
word3 2
word4 5
*/

//solution with shell
cat input.txt | awk '{a[$1]+=$2;} END {for(i in a){ print i,a[i];}}'
