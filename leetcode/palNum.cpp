/*Palindrome Number
   Determine whether an integer is a palindrome. 
   Do this without extra space.
 
 Some hints:
 Could negative integers be palindromes? (ie, -1)
 If you are thinking of converting the integer to string, 
 note the restriction of using extra space.
 You could also try reversing an integer. 
 However, if you have solved the problem "Reverse Integer", 
 you know that the reversed integer might overflow. 
 How would you handle such case?
 There is a more generic way of solving this problem.
 */
bool isPalindrome(int x) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(x<0) return false;
	int l,r,tmpx=x,cnt=0;
	while(tmpx){
		tmpx /= 10;
		cnt++;
	}
	tmpx = 1;
	for(int i=1;i<cnt;++i) tmpx *= 10;
	while(x&&cnt>0){
		r = x%10;
		l = x/tmpx;
		cnt -= 2;
		x %= tmpx;
		x /= 10;
		tmpx /= 100;
		if(l!=r) return false;
	}
	return true;
}
