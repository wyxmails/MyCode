#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main(int argc,char*argv[]){
	int num;
	char strin[50];
	int outnum;
	char mularr[100];
	mularr['1']=1;
	mularr['0']=0;
	mularr['A']=mularr['B']=mularr['C']=mularr['2']=2;
	mularr['D']=mularr['E']=mularr['F']=mularr['3']=3;
	mularr['G']=mularr['H']=mularr['I']=mularr['4']=4;
	mularr['J']=mularr['K']=mularr['L']=mularr['5']=5;
	mularr['M']=mularr['N']=mularr['O']=mularr['6']=6;
	mularr['P']=mularr['R']=mularr['S']=mularr['7']=7;
	mularr['T']=mularr['U']=mularr['V']=mularr['8']=8;
	mularr['W']=mularr['X']=mularr['Y']=mularr['9']=9;
	map<int,int> mapresult;
	cin>>num;
	gets(strin);
	mapresult.clear();
	while(num>0){
		outnum = 0;
		gets(strin);
		for(int i=0,count=0;count<7&&strin[i]!='\0'&&i<50;++i){
			if(strin[i]!='-'){
					outnum = outnum*10 + mularr[strin[i]];
					count++;
			}
		}
		if(mapresult.find(outnum)!=mapresult.end()){mapresult[outnum]++;}
		else {mapresult[outnum]=1;}
		num--;
	}
	bool flag = false;
	map<int,int>::iterator it;
	for(it=mapresult.begin();it!=mapresult.end();++it){
		if((*it).second>1){
			flag = true;
			printf("%03d-%04d %d\n",(*it).first/10000,(*it).first%10000,(*it).second);
		}
	}
	if(!flag) cout << "No duplicates." << endl;
	return 0;
}
