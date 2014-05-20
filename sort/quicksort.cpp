#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int a[],int start,int end){
	int tmp = a[end];
	int buf;
	int i=start-1;
	for(int j=start;j<end;++j){
		if(a[j]<tmp){
			i++;
			buf = a[i];
			a[i] = a[j];
			a[j] = buf;
		}
	}
	i++;
	a[end] = a[i];
	a[i] = tmp;
	return i;
}

int qsort(int a[],int start,int end){
	if(end<=start) return 0;
	int mid = partition(a,start,end);
	qsort(a,start,mid-1);
	qsort(a,mid+1,end);
	return 0;
}

int main(int argc,char*argv[]){
	int a[10];
	srand(time(0));
	cout << "orig:	";
	for(int i=0;i<10;++i){
	   	a[i] = rand()%100;;
		cout << a[i] << " ";
	}
	cout << endl;
	int len = sizeof(a)/sizeof(a[0]);
	qsort(a,0,len-1);
	cout << "sorted:	";
	for(int i=0;i<10;++i){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
