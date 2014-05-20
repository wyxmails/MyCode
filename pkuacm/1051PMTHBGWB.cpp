#include <iostream>
#include <string>
using namespace std;
int number[100];

void toCode(char c,int pos,string & codestr){
	switch(c){
		case 'A': codestr+=".-";number[pos]=2;break;
		case 'B': codestr+="-...";number[pos]=4;break;
		case 'C': codestr+="-.-.";number[pos]=4;break;
		case 'D': codestr+="-..";number[pos]=3;break;
		case 'E': codestr+=".";number[pos]=1;break;
		case 'F': codestr+="..-.";number[pos]=4;break;
		case 'G': codestr+="--.";number[pos]=3;break;
		case 'H': codestr+="....";number[pos]=4;break;
		case 'I': codestr+="..";number[pos]=2;break;
		case 'J': codestr+=".---";number[pos]=4;break;
		case 'K': codestr+="-.-";number[pos]=3;break;
		case 'L': codestr+=".-..";number[pos]=4;break;
		case 'M': codestr+="--";number[pos]=2;break;
		case 'N': codestr+="-.";number[pos]=2;break;
		case 'O': codestr+="---";number[pos]=3;break;
		case 'P': codestr+=".--.";number[pos]=4;break;
		case 'Q': codestr+="--.-";number[pos]=4;break;
		case 'R': codestr+=".-.";number[pos]=3;break;
		case 'S': codestr+="...";number[pos]=3;break;
		case 'T': codestr+="-";number[pos]=1;break;
		case 'U': codestr+="..-";number[pos]=3;break;
		case 'V': codestr+="...-";number[pos]=4;break;
		case 'W': codestr+=".--";number[pos]=3;break;
		case 'X': codestr+="-..-";number[pos]=4;break;
		case 'Y': codestr+="-.--";number[pos]=4;break;
		case 'Z': codestr+="--..";number[pos]=4;break;
		case '_': codestr+="..--";number[pos]=4;break;
		case '.': codestr+="---.";number[pos]=4;break;
		case ',': codestr+=".-.-";number[pos]=4;break;
		case '?': codestr+="----";number[pos]=4;break;
		default: break; 
	}
	return;
}
void toStr(string str){
		if(str==".-") cout << "A";
		else if(str=="-...") cout << "B";
		else if(str=="-.-.") cout << "C";
		else if(str=="-..") cout << "D";
		else if(str==".") cout << "E";
		else if(str=="..-.") cout << "F";
		else if(str=="--.") cout << "G";
		else if(str=="....") cout << "H";
		else if(str=="..") cout << "I";
		else if(str==".---") cout << "J";
		else if(str=="-.-") cout << "K";
		else if(str==".-..") cout << "L";
		else if(str=="--") cout << "M";
		else if(str=="-.") cout << "N";
		else if(str=="---") cout << "O";
		else if(str==".--.") cout << "P";
		else if(str=="--.-") cout << "Q";
		else if(str==".-.") cout << "R";
		else if(str=="...") cout << "S";
		else if(str=="-") cout << "T";
		else if(str=="..-") cout << "U";
		else if(str=="...-") cout << "V";
		else if(str==".--") cout << "W";
		else if(str=="-..-") cout << "X";
		else if(str=="-.--") cout << "Y";
		else if(str=="--..") cout << "Z";
		else if(str=="..--") cout << "_";
		else if(str=="---.") cout << ".";
		else if(str==".-.-") cout << ",";
		else if(str=="----") cout << "?";
}
int main(int argc,char*argv[]){
	int N,count;
	string str,tmpstr,codestr,outstr;
	string arr[30];
	cin>>N;
	count=1;
	while(count<=N){
		cin>>str;
		codestr="";
		for(int i=0;i<str.size();++i){
			toCode(str[i],i,codestr);
		}
		cout << count << ": ";
		int j=str.size()-1;
		for(int i=0;i<codestr.size()&&j>=0;i+=number[j],j--){
			tmpstr = "";
			for(int k=i;k<i+number[j];k++) tmpstr+=codestr[k];
			toStr(tmpstr);
		}
		cout << endl;
		count++;
	}
	return 0;
}
