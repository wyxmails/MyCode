#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cnt[26];
int firstPos[26];
char findFirstU(const char*str){
	if(str==NULL) return '\0';
	if(*str=='\0') return '\0';
	for(int i=0;i<26;++i){
		cnt[i] = 0;
		firstPos[i] = -1;
	}
	const char *p = str;
	while(*p!='\0'){
		int idx = *p - 'a';
		if(cnt[idx]==0) firstPos[idx] = p-str;
		cnt[idx]++;
		p++;
	}
	int miniPos = p-str+1;
	int pos=-1;
	for(int i=0;i<26;++i){
		if(cnt[i]==1){
			if(firstPos[i]<miniPos) {
				miniPos = firstPos[i];
				pos = i;
			}
		}
	}
	if(pos==-1) return '\0';
	else return char('a'+pos);
}

int main(){
	char arr[1024];
	memset(arr,sizeof(arr),0);
	strcpy(arr,"acsdfaweifjcahgkuhruihfdsankjlas");
	cout << arr << endl;
	cout << findFirstU(arr) << endl;
}
