#include <iostream>
using namespace std;

int main(int argc,char*argv[]){
	int N,sum,group,start,end;
	int i;
	cin>>N;
	sum=0;
	for(i=2;i<=N;++i){
		sum += i;
		if(sum>N){
			sum -=i;
			i--;
			break;
		}
		if(sum==N){
			break;
		}
	}
	start = 2;
	end = i;
	group = i-1;
	if(sum==N){
		for(int j=start;j<end;++j){
			cout << j << " ";
		}
		cout << end << endl;
	}else{
		if((N-sum)/group){
			start += (N-sum)/group;
			end += (N-sum)/group;
		}
		int pos, count=0;
		pos = (N-sum)%group;
		if(pos){
		   	end += 1;
			while(count<group-pos){
				cout << start+count << " ";
				count++;
			}
			start = start+count+1;
		}
		for(int j=start;j<end;++j){
			cout << j << " ";
		}
		cout << end <<endl;

	}
	return 0;
}
