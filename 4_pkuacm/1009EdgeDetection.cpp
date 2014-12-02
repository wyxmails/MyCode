#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct desc{
	long start;
	long end;
	long value;
}desc;

int main(int argc,char*argv[]){
	long long keyarr[1001];
	int valarr[1001];
	map<long long,int> mapkv;
	long long width,number,count,pairnum;
	int tmpvalue,value,maxval;
	bool flag;
	desc outunit;
	desc tmpout;
	cin>>width;
	while(width){
		cout << width << endl;
		mapkv.clear();
		count = 0;
		if(width==1){
			flag = false;
			cin>>value>>number;
			count = number;
			tmpvalue = value;
			cin>>value>>number;
			while(value&&number){
				flag = true;
				cout << "0 " << count-1 << endl;
				cout << abs(tmpvalue-value) << " 2" << endl;
				count = number;
				tmpvalue = value;
				cin>>value>>number;
			}
			if(flag&&count>1){
				cout << "0 " << count-1 << endl;
				cout << "0 0" << endl;
				cin>>width;
				continue;
			}else{
				cout << "0 " << count << endl;
				cout << "0 0" << endl;
				cin>>width;
				continue;
			}
		}
		cin>>value>>number;
		long i=0;
		if(number>width+1) pairnum = number-width;
		else pairnum = 1;
		while(value||number){
			count += number;
			keyarr[i] = count;
			valarr[i] = value;
			for(long j=pairnum;j<=keyarr[i];++j) mapkv[j]=valarr[i];
			i++;
			cin>>value>>number;
			if(number>width+1) pairnum=keyarr[i-1]+number-width;
			else pairnum=keyarr[i-1]+1;
			for(long j=keyarr[i-1]+1;j<pairnum&&j<=keyarr[i-1]+width+1;++j){
				mapkv[j] = value;
			}
		}
		pairnum = i;
		if(pairnum==1){
			cout << "0 " << count << endl;
			cin>>width;
			continue;
		}
		if(keyarr[0]>width+1){
			if(keyarr[0]%width){
			cout << "0 " << keyarr[0]-width-1 << endl;
			outunit.start = keyarr[0]-width;
			outunit.end = keyarr[0]-width-1;
			}else{
				cout << "0 " << keyarr[0]-width << endl;
				outunit.start = keyarr[0]-width+1;
				outunit.end = keyarr[0]-width;
			}
		}else{
			outunit.start = 1;
			outunit.end = 0;
		}
		outunit.value = 256;
		for(i=0;i<pairnum;++i){
			if(i==pairnum-1){
				if(keyarr[i]>outunit.end){
					if(outunit.value){
						cout << outunit.value << " " <<outunit.end-outunit.start+1 << endl;
						cout << "0 " << keyarr[i]-outunit.end << endl;
					}else{
						cout << outunit.value << " " << keyarr[i]-outunit.start+1 << endl;
					}
				}else{
					cout << outunit.value << " " <<outunit.end-outunit.start+1 << endl;
				}
				break;
			}
			if(i!=pairnum-1&&keyarr[i]-width-1>outunit.end&&mapkv.find(outunit.end+1)==mapkv.end()){
				cout <<outunit.value << " " << outunit.end-outunit.start+1 << endl;
				outunit.start = outunit.end+1;
				outunit.end = keyarr[i]-width-1;
				cout << "0 " << outunit.end-outunit.start+1 << endl;
				outunit.start = outunit.end+1;
			}
			for(long j=outunit.end+1;j<=keyarr[i]+width+1;++j){
				if(mapkv.find(j)==mapkv.end()) break;
				tmpvalue = 0;
				if(j%width==1){
					if(j>width){
						if(mapkv.find(j-width)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j-width]));
						if(mapkv.find(j-width+1)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j-width+1]));
					}
					if(j<count-width){
						if(mapkv.find(j+width)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j+width]));
						if(mapkv.find(j+width+1)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j+width+1]));
					}
					if(mapkv.find(j+1)!=mapkv.end())
				   		tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j+1]));
				}else if(j%width==0){
					if(j>width){
						if(mapkv.find(j-width)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j-width]));
						if(mapkv.find(j-width-1)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j-width-1]));
					}
					if(j<=count-width){
						if(mapkv.find(j+width)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j+width]));
						if(mapkv.find(j+width-1)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j+width-1]));
					}
				   	if(mapkv.find(j-1)!=mapkv.end())
						tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j-1]));
				}else{
				   	if(mapkv.find(j+1)!=mapkv.end()&&mapkv.find(j)!=mapkv.end())
						tmpvalue = max(abs(mapkv[j]-mapkv[j+1]),tmpvalue);
					if(mapkv.find(j-1)!=mapkv.end())
						tmpvalue = max(abs(mapkv[j]-mapkv[j-1]),tmpvalue);
					if(j>width){
						if(mapkv.find(j-width)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j-width]));
						if(mapkv.find(j-width+1)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j-width+1]));
						if(mapkv.find(j-width-1)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j-width-1]));
					}
					if(j<count-width){
						if(mapkv.find(j+width)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j+width]));
						if(mapkv.find(j+width+1)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j+width+1]));
						if(mapkv.find(j+width-1)!=mapkv.end())
							tmpvalue = max(tmpvalue,abs(mapkv[j]-mapkv[j+width-1]));
					}
				}
				if(outunit.value<=255&&tmpvalue!=outunit.value){
					cout << outunit.value << " " << outunit.end-outunit.start+1 << endl;
					outunit.start = j;
					outunit.end = j;
					outunit.value = tmpvalue;
				}else{
					outunit.value = tmpvalue;
					outunit.end = j;
				}
			}
		}
		cout << "0 0" << endl;
		cin>>width;
	}
	cout << "0" << endl;
	return 0;
	
}
