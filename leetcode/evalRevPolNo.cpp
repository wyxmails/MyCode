#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.
*
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.
* 
* Some examples:
*   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
*   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
int evalRPN(vector<string> &tokens) {
	int n = tokens.size();
	if(n<=2) return atoi(tokens[n-1].c_str());
	vector<int> vec;
	int t1,t2;
	for(int i=0;i<n;++i){
		if((int)(tokens[i][0]-'0')<=9&&(int)(tokens[i][0]-'0')>=0){
			vec.push_back(atoi(tokens[i].c_str()));
			continue;
		}
		if(tokens[i].size()>1){
			string s = tokens[i].substr(1);
			if(tokens[i][0]=='-') vec.push_back(0-atoi(s.c_str()));
			else vec.push_back(atoi(s.c_str()));
			continue;
		}
		if(vec.size()<2) return 0;
		t2 = vec.back();
		vec.pop_back();
		t1 = vec.back();
		vec.pop_back();
		if(tokens[i]=="+"){
			vec.push_back(t1+t2);
		}else if(tokens[i]=="-"){
			vec.push_back(t1-t2);
		}else if(tokens[i]=="*"){
			vec.push_back(t1*t2);
		}else if(tokens[i]=="/"){
			vec.push_back(t1/t2);
		}
	}
	return vec.back();
}

int evalRPN2(vector<string> &tokens) {
        stack<int> myS;
        int n = tokens.size();
        if(n==0) return 0;
        int v1,v2;
        for(int i=0;i<n;++i){
            if(tokens[i].size()>1||(tokens[i][0]-'0'>=0&&tokens[i][0]-'0'<10)){
                myS.push(atoi(tokens[i].c_str()));
            }else{
                if(myS.size()<2) return 0;
                v1 = myS.top();
                myS.pop();
                v2 = myS.top();
                myS.pop();
                if(tokens[i]=="+")
                    myS.push(v1+v2);
                else if(tokens[i]=="-")
                    myS.push(v2-v1);
                else if(tokens[i]=="*")
                    myS.push(v1*v2);
                else if(tokens[i]=="/"){
                    if(v1==0) myS.push(0);
                    else myS.push(v2/v1);
                }
            }
        }
        return myS.top();
}

int main(int argc,char*argv[]){
	return 0;
}
