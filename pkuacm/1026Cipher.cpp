#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main(int argc,char*argv[]){
	int N,K,lenth,i,tmp,count;
	int keys[200], mespos[200],keyrank[200];
	char tmpmes[201],outputs[200];
	cin>>N;
	while(N!=0){
		for(i=0;i<N;++i){
			keyrank[i] = i+1;
		}
		for(i=0;i<N;++i){
			cin>>keys[i];
		}
		//count the rank of every key
		for(int j=0;j<N;++j){
			count=0;
			do{
				keyrank[j] = keys[keyrank[j]-1];
				count++;
			}while((j+1)!=keyrank[j]);
			keyrank[j]=count;
		}
		cin>>K;
		while(K!=0){
			for(i=0;i<N;++i){
				outputs[i] = ' ';
			}
			gets(tmpmes);
			for(i=1;i<=200&&tmpmes[i]!='\0';++i){
				mespos[i] = i;
			}
			lenth = i;
			for(int j=1;j<lenth;j++){
				for(i=0;i<K%keyrank[j-1];++i){
					mespos[j] = keys[mespos[j]-1];
				}
				outputs[mespos[j]-1] = tmpmes[j];
			}
			outputs[N]='\0';
			//OUTPUT
			puts(outputs);
			cin>>K;
		}
		cout << endl;
		cin>>N;
	}
	return 0;
}
