/*
 There is a building of 100 floors. 
 If an egg drops from the Nth floor or above, it will break. 
 If it's dropped from any floor below, it will not break. 
 You're given two eggs. 
 Find N, while minimizing the number of drops for the worst case.
 */
solution:
	1+2+3+...+N = 100; N*(N+1)/2 >=100; N=14;
