#include <iostream>
#include <algorithm>
using namespace std;

int cntBrac(char *p){
	int left = 0;
	int cnt = 0;
	char *s = p;
	while(*s!='\0'){
		if(*s=='(') left++;
		else if(*s==')'){
			if(left){
				left--;
				cnt++;
			}
		}
		s++;
	}
	return cnt;
}
int main(int argc,char*argv[]){
	int n;
	srand(time(0));
	cin>>n;
	char arr[n];
	for(int i=0;i<n;++i){
		if(rand()%2)	arr[i] = '(';
		else	arr[i] = ')';
		cout << arr[i];
	}
	cout << endl;
	cout << "pairs: " << cntBrac(arr) << endl;
	return 0;
}
