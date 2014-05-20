#include <iostream>
using namespace std;

int findOutlier(int A[],int len){
	int cnt1,cnt2,cnt3;
	int num1,num2,num3;
	int i=0;
	while(i<len&&A[i]==A[i+1]) i++;
	cnt1 = i+1;
	i++;
	while(i<len&&A[i]==A[i+1]) i++;
	cnt2 = i+1-cnt1;
	i++;
	if(cnt1!=cnt2){
		while(i<len&&A[i]==A[i+1]) i++;
		cnt3 = i+1-cnt1-cnt2;
		i++;
		if(cnt1==cnt3) return A[cnt1];
		if(cnt2==cnt3) return A[0];
	}
	if(i+cnt1>=len) return A[i+1];
	while(i<len){
		if(A[i]!=A[i+cnt1-1]||A[i]==A[i+cnt1]) return A[i];
		else i += cnt1;
	}
	return A[len-1];
}
int main()
{
	int A1[] = {2,2,3,3,4,4,4,5,5};
	int A2[] = {2,2,2,3,3,3,3,4,4,4};
	int A3[] = {2,3,4,5,6,7,8,8,9,10};
	
	cout << findOutlier(A1, 9)<< endl;
	cout << findOutlier(A2, 10)<< endl;
	cout << findOutlier(A3, 10)<< endl;
	return 0;
}
