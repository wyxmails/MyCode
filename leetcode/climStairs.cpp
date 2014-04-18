/*Climbing Stairs
 You are climbing a stair case. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. 
 In how many distinct ways can you climb to the top?
 */
int climbStairs(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(n<=0) return 0;
	if(n==1) return 1;
	if(n==2) return 2;
	int x1,x2,res;
	x1 = 1;x2 = 2;
	for(int i=3;i<=n;++i){
		res = x1+x2;
		x1 = x2;
		x2 = res;
	}
	return res;
}
