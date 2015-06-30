/*
Transpose File Total Accepted: 879 Total Submissions: 4003 My Submissions Question Solution 
Given a text file file.txt, transpose its content.

You may assume that each row has the same number of columns and each field is separated by the ' ' character.

For example, if file.txt has the following content:

name age
alice 21
ryan 30
Output the following:

name alice ryan
age 21 30
*/

# Read from the file file.txt and print its transposed content to stdout.

#END must be upper case
awk '
{
    for(k=1;k<=NF;++k) 
        a[NR][k]=$k
} 
END { 
    for(j=1;j<=NF;++j)
    {
        str = a[1][j];
        for(i=2;i<=NR;++i)
        {
            str= str" "a[i][j]
        }
        print str;
    }
}
' file.txt
