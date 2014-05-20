#include <iostream>
using namespace std;

int merge(int a[],int b[],int start,int mid,int end){
	int i,j,k;
	for(i=start,j=mid,k=start;i<mid&&j<end;k++){
		if(a[i]<a[j])	b[k] = a[i++];
		else if(a[i]>a[j]) b[k] = a[j++];
		else{
		   	b[k++] = a[i++];
			b[k] = a[j++];
		}
	}
	while(i<mid) b[k++] = a[i++];
	while(j<end) b[k++] = a[j++];
	return 0;
}

int msort(int a[],int b[],int step,int len){
	int start=0;
	while(start<=len-2*step){
		merge(a,b,start,start+step,start+2*step);
		start += 2*step;
	}
	if(start<=len-step){
		merge(a,b,start,start+step,len);
	}else{
		merge(a,b,start,len,len);
	}
	return 0;
}

int main(int argc,char*argv[]){
	int a[10],b[10];
	int step=1;
	int len = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<10;++i) a[i] = 10-i;
	cout << "orig:   ";
	for(int i=0;i<10;++i) cout << a[i] << " ";
	cout << endl;
	while(step<sizeof(a)/2){
		msort(a,b,step,len);
		step += step;
		msort(b,a,step,len);
		step += step;
	}
	cout << "sorted: ";
	for(int i=0;i<10;++i) cout << a[i] << " ";
	cout << endl;
}
