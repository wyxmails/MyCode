#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void countnum(const string nStr,int intArray[]);
void genNext(int intArray[],string strArray[],int index);
int main(int argc,char*argv[]){
	bool flag;
	string nStr="";
	string strArray[15];
	int intArray[10];
	for(int i=0;i<10;++i){
		intArray[i] = 0;
	}
	cin>>nStr;
	while('-'!=nStr[0]){
		flag = false;
		countnum(nStr,intArray);
		genNext(intArray,strArray,0);
		if(strArray[0].compare(nStr)==0){
			cout << nStr << " is self-inventorying" << endl;
			flag = true;
		}
		if(!flag){
			for(int i=1;i<15;++i){
				countnum(strArray[i-1],intArray);
				genNext(intArray,strArray,i);
				for(int j=i-1;j>=0;--j){
					if(strArray[i].compare(strArray[j])==0){
						if(1==(i-j)){
							flag = true;
							cout <<	 nStr << " is self-inventorying after " << i << " steps" << endl;
							break;
						}else{
							flag = true;
							cout << nStr << " enters an inventory loop of length " << i-j << endl;
							break;
						}
					}
				}
				if(flag)
					break;
			}
		}
		if(!flag)
			cout << nStr << " can not be classified after 15 iterations" << endl;
		nStr = 	"";
		cin>>nStr;
	}          	
	return 0;  	
}       
void genNext(int intArray[],string strArray[],int index){
		string tmpstr = "";
		string buffer1, buffer2;
		stringstream ss;
		for(int i=9;i>=0;--i){
			if(intArray[i]==0)
				continue;
			ss.clear();
			ss << intArray[i];
			ss >> buffer1;
			ss.clear();
			ss << i;
			ss >> buffer2;
			tmpstr = buffer1 + buffer2 + tmpstr;
		}
		strArray[index] = tmpstr;
}
void countnum(const string nStr,int intArray[]){
	for(int i=0;i<10;++i){
		intArray[i] = 0;
	}
	for(int i=0;i<nStr.size();++i){
		switch(nStr[i]){
			case '0':
				intArray[0]++;
				break;
			case '1':
				intArray[1]++;
				break;
			case '2':
				intArray[2]++;
				break;
			case '3':
				intArray[3]++;
				break;
			case '4':
				intArray[4]++;
				break;
			case '5':
				intArray[5]++;
				break;
			case '6':
				intArray[6]++;
				break;
			case '7':
				intArray[7]++;
				break;
			case '8':
				intArray[8]++;
				break;
			case '9':
				intArray[9]++;
				break;
		}
	}
}	
