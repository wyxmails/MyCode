/*
 An array A contains all the integers from 0 through n, 
 except for one number which is missing. 
 In this problem, 
 we cannot access an entire integer in A with a single operation. 
 The elements of A are represented in binary, 
 and the only operation we can use to access them is 
 "fetch thejth bit ofAfi]," which takes constant time. 
 Write code to find the missing integer. Can you do it in 0(n) time?
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool GetBit(int num,int bit){
	return num&(1<<bit);
}

int FindMiss(vector<int> vec){
	int n = vec.size();
	if(n==0) return 0;
	int ones,zeros;
	int res=0;
	for(int bit=0;bit<32;++bit){
		ones=zeros=0;
		for(int i=0;i<vec.size();++i){
			if(GetBit(vec[i],0)) ones++;
			else zeros++;
		}
		if(ones<zeros){
		   	res += (1<<bit);
			int i=0;
			while(i<vec.size()){
				if(!GetBit(vec[i],0)) vec.erase(vec.begin()+i);
				else{
					vec[i] >>= 1; 
					i++;
				}
			}
		}else{
			int i=0;
			while(i<vec.size()){
				if(GetBit(vec[i],0)) vec.erase(vec.begin()+i);
				else{
					vec[i] >>= 1;   
					i++;
				}
			}
		}
	
	}
	return res;
}

int FindMiss2(vector<int> vec,int col){
	vector<int> zeros;
	vector<int> ones;
	if(col>=32) return 0;
	int n = vec.size();
	for(int i=0;i<n;++i){
		if(GetBit(vec[i],col)) ones.push_back(vec[i]);
		else zeros.push_back(vec[i]);
	}
	if(ones.size()<zeros.size()){
		int v = FindMiss2(ones,col+1);
		return (v<<1)|1;
	}else{
	   	int v = FindMiss2(zeros,col+1);
		return (v<<1)|0;
	}
}

int FindMiss2(vector<int> vec){
	return FindMiss2(vec,0);
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%10;
	int target = rand()%(n+1);
	vector<int> vec(n);
	cout << n << " " << target << endl;
	for(int i=0;i<n;++i){
		if(i>=target){
			vec[i] = i+1;
			cout << i+1 << " ";
		}else{
			cout << i << " ";
		   	vec[i] = i;
		}
	}
	cout << endl;
	cout << FindMiss(vec) << endl;
	cout << FindMiss2(vec) << endl;
	return 0;
}
