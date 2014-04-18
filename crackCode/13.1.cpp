#include <iostream>
#include <fstream>
using namespace std;

void printLastKLines(ifstream &fin, int k){
	string line[k];
	int lines = 0;
	string tmp;
	while(getline(fin,tmp)){//&&!fin.eof()){
		line[lines%k] = tmp;
		++lines;
	}
	int start,cnt;
	if(lines<k){
		start = 0;
		cnt = lines;
	}else{
		start = lines%k;
		cnt = k;
	}
	for(int i=0;i<cnt;++i)
		cout << line[(start+i)%k]<<endl;
}

int main(int argc,char*argv[]){
	ifstream fin("13.1.in");
	int k;
	cout << "Please Input the line number: " << endl;
	cin>>k;
	printLastKLines(fin,k);
	fin.close();
	return 0;
}
