/*
 You have a basketball hoop and someone says that you can play one of two games.
 Game 1: Youget one shot to make the hoop.
 Game 2: You get three shots and you have to make two of three shots.
 If p is the probability of making a particular shot, 
 for which values ofp should you pick one game or the other?
 */
solution:
	game1 to win: p
	game2 to win: C(2,3)+C(3,3), c(3,3)=p*p*p, c(2,3) = 3*p*p*(1-p)
	p>3*p*p*(1-p)+p*p*p, p>3*p*p-2*p*p*p, 1>3*p-2*p*p, (2*p-1)(p-1) >0,
	because p<1, so p-1 is negative, so 2*p-1 should be negative, 
	2*p-1<0, p<0.5. 
	So when p<0.5, should play game1, 
	If p==0.5 or p==0.0 or p==1.0, both game have equal probability to win.
