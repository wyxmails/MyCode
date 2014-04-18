/*Multiply Strings
 Given two numbers represented as strings, 
 return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
 */
#include <iostream>
#include <algorithm>
using namespace std;
string multiply(string num1, string num2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	string str = "";
	str.assign(num1.size()+num2.size(),'0');
	string n1=num1;
	string n2=num2;
	for(int i=0;i<n1.size()/2;++i){
		char tmp = n1[i];
		n1[i] = n1[n1.size()-i-1];
		n1[n1.size()-i-1] = tmp;
	}
	for(int i=0;i<n2.size()/2;++i){
		char tmp = n2[i];
		n2[i] = n2[n2.size()-i-1];
		n2[n2.size()-i-1] = tmp;
	}
	for(int i=0;i<n1.size();++i){
		for(int j=0;j<n2.size();++j){
			int nu1 = n1[i]-'0';
			int nu2 = n2[j]-'0';
			int num = nu1*nu2+(str[i+j]-'0');
			if(num>9){
				str[i+j+1] += num/10;
			}
			str[i+j] = (char)(num%10 +'0');
		}
	}
	for(int i=0;i<str.size()/2;++i){
		char tmp = str[i];
		str[i] = str[str.size()-i-1];
		str[str.size()-i-1] = tmp;
	}
	int i=0;
	while(str[i]=='0'){
		str.erase(i,1);
		if(str.size()==0) break;
	}
	if(str.size()==0) str = "0";
	return str;
}

    string multiply1(string num1, string num2) {
		        // Note: The Solution object is instantiated only once and is reused by each test case.
		        string res;
				        res.assign(num1.size()+num2.size()+1,'0');
						    string n1 = num1;
							    string n2 = num2;
								    reverse(n1.begin(),n1.end());
									    reverse(n2.begin(),n2.end());
										    int t1,t2,carr=0;
											    for(int i=0;i<n1.size();++i){
													        for(int j=0;j<n2.size();++j){
																            t1 = int(n1[i]-'0');
																			            t2 = int(n2[i]-'0');
																						            t1 *= t2;
																									            t2 = int(res[i+j]-'0');
																												            t1 += (t2+carr);
																															            if(t1>9){
																																			                carr = t1/10;
																																							                res[i+j] = char(t1%10+'0');
																																											            }else{
																																															                carr = 0;
																																																			                res[i+j] = char(t1+'0');
																																																							            }
																																		        }
															    }
												    reverse(res.begin(),res.end());
													    int i=0;
														    while(res[i]=='0'){
																        res.erase(i,1);
																		        if(res.size()==0) break;
																				    }
															    if(res.size()<=0) res = "0";
																    return res;

																	    }

int main(){
	string n1 = "1";
	string n2 = "1";
	cout <<multiply1(n1,n2) << endl; 
}
