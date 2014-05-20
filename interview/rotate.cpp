#include <iostream>
using namespace std;

void rotate(int arr[],int n,int x){
	int tmp,cnt,i,s;
	i=s=0;
	cnt=1;
	while(cnt<n){
		cnt++;
		tmp = arr[i];
		arr[i] = arr[(i+x)%n];
		i = (i+x)%n;
		arr[i] = tmp;
		if(s==((i+x)%n)){
			i++;
			s=i;
			cnt++;
		}
	}
}

int main(int argc,char*argv[]){
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;++i){
		arr[i] = i+1;
		cout << arr[i] << " ";
	}
	cout << endl;
	rotate(arr,n,x);
	for(int i=0;i<n;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
