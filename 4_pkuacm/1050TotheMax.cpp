#include <iostream>
using namespace std;

#define minnum (-127)*100-1;
int arr[100][100];
int maxarr[100][100][100];

int line(int i,int left,int right){
	int sum=0;
	for(;left<=right;++left){
		sum += arr[i][left];
	}
	return sum;
}

int main(int argc,char*argv[]){
	int N;
	int maxVal,tmpres,left,right;
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
		}
	}
	maxVal = minnum;
	for(int i=0;i<N;++i){
		for(left=0;left<N;++left){
			for(right=left;right<N;right++){
				tmpres = line(i,left,right);
				if(i>0)
					maxarr[i][left][right] = max(maxarr[i-1][left][right]+tmpres,tmpres);
				else
					maxarr[i][left][right] = tmpres;
				maxVal = maxVal>maxarr[i][left][right]?maxVal:maxarr[i][left][right];
			}
		}
	}
	cout << maxVal << endl;
	return 0;
}
