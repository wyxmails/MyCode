#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int kthSmall(int a[],int start,int end,int pos){
	if(end<=start) return a[start];
	int mid = a[end];
	int j=start-1;
	int buf;
	for(int i=start;i<end;++i){
		if(a[i]<mid){
			j++;
			buf = a[j];
			a[j] = a[i];
			a[i] = buf;
		}
	}
	j++;
	a[end] = a[j];
	a[j] = mid;
	if(j+1==pos){
		return a[j];
	}else if(j+1<pos){
		return kthSmall(a,j+1,end,pos);
	}else{
		return kthSmall(a,start,j-1,pos);
	}
}

int main(int argc,char*argv[]){
	int a[10],k;
	srand(time(0));
	k=rand()%9+1;
	//int a[10]={88,95,39,78,8,78,18,21,18,8};
	cout << "orig:	";
	for(int i=0;i<10;++i){
		a[i] = rand()%100;
		cout << a[i] << " ";
	}
	cout << endl;
	int len = sizeof(a)/sizeof(a[0]);
	int ks = kthSmall(a,0,len-1,k);
	cout << k << "th Small: " << ks << endl;
	return 0;
}
