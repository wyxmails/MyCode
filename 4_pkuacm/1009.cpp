#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(int argc,char*argv[]){
	int width,value,number,count,index,pairnum;
	int tmp,tmpvalue,outvalue,outstart,outend;
	int keys[1001];
	int values[1001];
	map<int,int> mapresult;
	cin>>width;
	while(width){
		cin>>value>>number;
		index = 0;
		count=0;
		while(value||number){
			count += number;
			keys[index] = count;
			values[index] = value;
			index++;
			cin>>value>>number;
		}
		map<int,int>::iterator it;
		pairnum = index;
		for(index=0;index<pairnum;++index){
			tmpvalue = 0;
				int i=index;
				if(keys[index]%width!=0&&keys[index]-width+1>=1){
					while(i>0&&keys[i]>=keys[index]-width+1) i--;
					i++;
					if(keys[i]<=keys[index]-width+1){
						tmpvalue = max(tmpvalue,abs(values[i]-values[index]));
						if(mapresult.find(keys[i])!=mapresult.end()) mapresult[keys[i]] = max(mapresult[keys[i]],abs(values[i]-values[index]));
						else mapresult[keys[i]] = abs(values[i]-values[index]);
					}
				}
				cout << values[i] << " " << values[index] << endl;
				cout << index<<" tmpvalue: " << tmpvalue << endl;
				if(keys[index]-width>=1){
					while(i>0&&keys[i]>=keys[index]-width) i--;
					i++;
					if(keys[i]<=keys[index]-width){ 
						tmpvalue = max(tmpvalue,abs(values[i]-values[index]));
						if(mapresult.find(keys[i])!=mapresult.end()) mapresult[keys[i]] = max(mapresult[keys[i]],abs(values[i]-values[index]));
						else mapresult[keys[i]] = abs(values[i]-values[index]);
					}
				}
				cout <<index<< " tmpvalue: " << tmpvalue << endl;
				if(keys[index]%width!=1&&keys[index]-width-1>=1){
					while(i>0&&keys[i]>=keys[index]-width-1) i--;
					i++;
					if(keys[i]<=keys[index]-width){
						tmpvalue = max(tmpvalue,abs(values[i]-values[index]));
						if(mapresult.find(keys[i])!=mapresult.end()) mapresult[keys[i]] = max(mapresult[keys[i]],abs(values[i]-values[index]));
						else mapresult[keys[i]] = abs(values[i]-values[index]);
					}
				}
				cout << index<<" tmpvalue: " << tmpvalue << endl;
				i=index;
				if(keys[index]%width!=1&&keys[index]+width-1<=count){
					while(i<pairnum-1&&keys[i]<keys[index]+width-1) i++;
					if(keys[i]>=keys[index]+width-1){
						tmpvalue = max(tmpvalue,abs(values[i]-values[index]));
						if(mapresult.find(keys[i])!=mapresult.end()) mapresult[keys[i]] = max(mapresult[keys[i]],abs(values[i]-values[index]));
						else mapresult[keys[i]] = abs(values[i]-values[index]);
					}
				}
				cout << index <<" tmpvalue: " << tmpvalue << endl;
				if(keys[index]+width<=count){
					while(i<pairnum-1&&keys[i]<keys[index]+width) i++;
					if(keys[i]>=keys[index]+width){
						tmpvalue = max(tmpvalue,abs(values[i]-values[index]));
						if(mapresult.find(keys[i])!=mapresult.end()) mapresult[keys[i]] = max(mapresult[keys[i]],abs(values[i]-values[index]));
						else mapresult[keys[i]] = abs(values[i]-values[index]);
					}
				}
				cout << index<<" tmpvalue: " << tmpvalue << endl;
				if(keys[index]%width!=0&&keys[index]+width+1<=count){
					while(i<pairnum-1&&keys[i]<keys[index]+width+1) i++;
					if(keys[i]>=keys[index]+width+1){
						tmpvalue = max(tmpvalue,abs(values[i]-values[index]));
						if(mapresult.find(keys[i])!=mapresult.end()) mapresult[keys[i]] = max(mapresult[keys[i]],abs(values[i]-values[index]));
						else mapresult[keys[i]] = abs(values[i]-values[index]);
					}
				}
				cout <<index<< " tmpvalue: " << tmpvalue << endl;
				i=index;
				if(keys[index]%width!=0&&keys[index]+1<=count){
					while(i<pairnum-1&&keys[i]<keys[index]+1) i++;
					if(keys[i]>=keys[index]+1){
						tmpvalue = max(tmpvalue,abs(values[i]-values[index]));
						if(mapresult.find(keys[i])!=mapresult.end()) mapresult[keys[i]] = max(mapresult[keys[i]],abs(values[i]-values[index]));
						else mapresult[keys[i]] = abs(values[i]-values[index]);
					}	
				}
				cout <<index<< " tmpvalue: " << tmpvalue << endl;
				i=index;
				if(keys[index]%width!=1&&keys[index]-1>=1){
					while(i>0&&keys[i]>=keys[index]-1) i--;
					i++;
					if(keys[i]<=keys[index]-1){
						tmpvalue = max(tmpvalue,abs(values[i]-values[index]));
						if(mapresult.find(keys[i])!=mapresult.end()) mapresult[keys[i]] = max(mapresult[keys[i]],abs(values[i]-values[index]));
						else mapresult[keys[i]] = abs(values[i]-values[index]);
					}
				}
				cout <<index<< " tmpvalue: " << tmpvalue << endl;
			it = mapresult.find(keys[index]);
			if(it!=mapresult.end()) mapresult[keys[index]] = max((*it).second,tmpvalue);
			else mapresult[keys[index]] = tmpvalue;
				cout <<index<< " tmpvalue: " << tmpvalue << endl;
			cout << "key[0]: " << mapresult[keys[0]] << endl;
		}
		if(keys[0]-width-1>=1){
			cout << "0 " << keys[0]-width-1<< endl;
			outstart = keys[0]-width;
			outend = keys[0]-width;
			outvalue = mapresult[keys[0]-width];
		}else{
			outstart = 1;
			outend = 1;
			if(mapresult.find(1)!=mapresult.end())
				outvalue = mapresult[1];
			else outvalue = mapresult[keys[0]];
			cout << "key[0]: " << mapresult[keys[0]] << endl;
		}
		it = mapresult.begin();
		while(tmp<=keys[index]+width+1&&it!=mapresult.end()){
				tmp = (*it).first;
				if((*it).second!=outvalue){
					cout << "a"<<outvalue << " " << outend-outstart << endl;
					outvalue = (*it).second;
					outstart = (*it).first;
					outend = (*it).first;
				}else{
					outvalue = (*it).second;
					outend = (*it).first;
				}
			it++;
		}
		for(index=1;index<pairnum-1;++index){
			if(keys[index]%width&&keys[index]-width>tmp){
				if(outvalue!=0){
					cout <<"b"<< outvalue << " " << outend-outstart+1 << endl;
					outvalue = 0;
					outstart = tmp;
				}
				outend = keys[index]-index-1;
			}else if(keys[index]%width==0&&keys[index]-width+1>tmp){
				if(outvalue!=0){
					cout << "c" <<outvalue << " " << outend-outstart+1 << endl;
					outvalue = 0;
					outstart = tmp;
				}
				outend = keys[index]-index;
			}
			tmp = keys[index]-index>outend?keys[index]-index:outend+1;
			it = mapresult.find(tmp);
			while(tmp<=keys[index]+width+1&&it!=mapresult.end()){
				tmp = (*it).first;
					if((*it).second!=outvalue){
						cout << "d" <<outvalue << " " << outend-outstart << endl;
						outvalue = (*it).second;
						outstart = (*it).first;
						outend = (*it).first;
					}else{
						outvalue = (*it).second;
						outend = (*it).first;
					}
				it++;
			}
		}
		if(keys[index]>outend){
			if(outvalue!=0){
				cout << "e" <<outvalue << " " << outend-outstart+1 << endl;
				cout << "0 " << keys[index]-outend<<endl;
			}
		}else{
			cout << "f" <<outvalue << " " << outend-outstart+1 << endl;
		}
		cout << "0 0" << endl;
		cin>>width;
	}
	cout << "0" << endl;
	return 0;
}
