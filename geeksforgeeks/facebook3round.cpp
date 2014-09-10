/*
 All three rounds were coding round

Round 1 45 mins
Reverse a Link list (code it)
Find two elements in sorted array which sums to a given number (code it)
Difference between  C++ and java
Advantage and disadvantage Garbage memory collector in Java

Round 2 45 mins
Write the following function
double  solveForX(string s) {   }
input will be linear equation in x with +1 or -1 coefficient.
output will be value of x.
s can be as follows
i/p   x + 9 – 2 -4 + x = – x + 5 – 1 + 3 – x   o/p  1.00
i/p    x + 9 -1 = 0  o/p -8.00
i/p    x + 4 = – 3 – x  o/p  -3.500
it has second part
if the i/p string can have ‘(‘ or  ‘)’
x + 9 – 2 -(4 + x) = – (x + 5 – 1 + 3) – x
x + 9 + (3 + – x – ( -x + (3 – (9 – x) +x = 9 -(5 +x )

round 3
Sort an array  using below operation
An operation called flip which runs in O(1)  <<<<< important this is given
for an array ‘a’
a.flip(index)  this operation will reverse the array from index to end of the array
for eg:
a[]= {1,4,0,6,7};
a.flip(0) = 7,6,0,4,1 // reverse from 0 to end
a.flip(2) = 1,4,7,6,0 // reverse from 2nd index to end
a.flip(4) 1,4,0,6,7 // no change in array reverse from end to end
First do it in O(n^2)
Then in O(nlogn)
 */


