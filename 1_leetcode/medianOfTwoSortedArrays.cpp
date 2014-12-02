/* Median of Two Sorted Arrays
 There are two sorted arrays A and B of size m and n respectively. 
 Find the median of the two sorted arrays. 
 The overall run time complexity should be O(log (m+n)).
 */
double findMedianSortedArrays(int A[], int m, int B[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int h1,h2;
	h1 = m/2;
	h2 = n/2;
	if((m+n)%2){
		if(m<1&&n) return B[n/2];
		if(n<1&&m) return A[m/2];
		if(m==1){
			if(A[h1]>B[h2]) return B[h2];
			else if(A[h1]<B[h2-1]) return B[h2-1];
			else return A[h1];
		}
		if(n==1){
			if(B[h2]>A[h1]) return A[h1];
			else if(B[h2]<A[h1-1]) return A[h1-1];
			else return B[h2];
		}
		if(A[h1]==B[h2]){
			return A[h1];
		}else if(A[h1]<B[h2]){
			if(m>n){
				return findMedianSortedArrays(&A[h2],m-h2,B,n-h2);
			}else{
				return findMedianSortedArrays(&A[h1], m-h1, B, n-h1);
			}
		}else{
			if(m>n){
				return findMedianSortedArrays(A, m-h2, &B[h2], n-h2);
			}else{
				return findMedianSortedArrays(A, m-h1, &B[h1], n-h1);
			}
		}
	}else{
		if(m<1&&n) return (double)(B[n/2]+B[n/2-1])/2.0;
		if(n<1&&m) return (double)(A[m/2]+A[m/2-1])/2.0;
		if(m==1&&n==1) return (double)(A[h1]+B[h2])/2.0;
		if(m==1){
			if(A[h1]>B[h2+1]) return (B[h2]+B[h2+1])/2.0;
			else if(A[h1]<B[h2-1]) return (B[h2-1]+B[h2])/2.0;
			else return (A[h1]+B[h2])/2.0;
		}
		if(n==1){
			if(B[h2]>A[h1+1]) return (A[h1]+A[h1+1])/2.0;
			else if(B[h2]<A[h1-1]) return (A[h1-1]+A[h1])/2.0;
			else return (A[h1]+B[h2])/2.0;
		}
		if(m==2){
			if(A[h1]<=B[h2]&&A[h1-1]>=B[h2-1]) 
				return (A[h1-1]+A[h1])/2.0;
			else if(A[h1]>=B[h2]&&A[h1-1]<=B[h2-1])
				return (B[h2-1]+B[h2])/2.0;
			else if(A[h1]<B[h2]&&A[h1]>B[h2-1])
				return (A[h1]+B[h2-1])/2.0;
			else if(A[h1]>B[h2]&&B[h2]>A[h1-1])
				return (B[h2]+A[h1-1])/2.0;
		}
		if(n==2){
			if(B[h2]>=A[h1]&&A[h1-1]>=B[h2-1])
				return (A[h1-1]+A[h1])/2.0;
			if(A[h1]>=B[h2]&&B[h2-1]>=A[h1-1])
				return (B[h2-1]+B[h2])/2.0;
			else if(B[h2]<A[h1]&&B[h2]>A[h1-1])
				return (B[h2]+A[h1-1])/2.0;
			else if(B[h2]>A[h1]&&A[h1]>B[h2-1])
				return (A[h1]+B[h2-1])/2.0;
		}
		if(A[h1]<B[h2]){
			if(m>n){
				if(m%2==0&&A[h1]>B[h2-1])
					return findMedianSortedArrays(&A[h2-1],m-h2+1,B,n-h2+1);
				else
					return findMedianSortedArrays(&A[h2],m-h2,B,n-h2);
			}else{
				if(m%2==0&&A[h1]>B[h2-1])
					return findMedianSortedArrays(&A[h1-1], m-h1+1, B, n-h1+1);
				else 
					return findMedianSortedArrays(&A[h1], m-h1, B, n-h1);
			}
		}else{
			if(m>n){
				if(m%2==0&&A[h1-1]<B[h2])
					return findMedianSortedArrays(A, m-h2+1, &B[h2-1], n-h2+1);
				else 
					return findMedianSortedArrays(A, m-h2, &B[h2], n-h2);
			}else{
				if(m%2==0&&A[h1-1]<B[h2])
					return findMedianSortedArrays(A, m-h1+1,&B[h1-1],n-h1+1);
				else
					return findMedianSortedArrays(A, m-h1, &B[h1], n-h1);
			}
		}
	}
}
