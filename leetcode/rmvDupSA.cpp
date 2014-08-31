/*Remove Duplicates from Sorted Array
   Given a sorted array, 
   remove the duplicates in place such that 
   each element appear only once and return the new length.
 Do not allocate extra space for another array
 you must do this in place with constant memory.
 For example,
 Given input array A = [1,1,2],
 Your function should return length = 2, and A is now [1,2].
 */
int removeDuplicates(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(n<=1) return n;
	int i=0,len=0;
	int cur;
	while(i<n){
		cur = A[i];
		while(i<n&&A[i]==cur){
			i++;
		}
		A[len++] = A[i-1];
	}
	return len;
}
