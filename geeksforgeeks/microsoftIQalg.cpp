/*
 What are the different ways to say, the value of x can be either a 0 or a 1. Apparently the if then else solution has a jump when written out in assembly.
 if (x == 0)
 	y = a
 else
 	y = b
 There is a logical, arithmetic and a datastructure soln to the above problem. 
 */
solutions:
1, y = x?b:a;
2, y = (!x)*a+x*b;
3, y = a+(b-a)x;
4, A[2] = {a,b}; y = A[x];
