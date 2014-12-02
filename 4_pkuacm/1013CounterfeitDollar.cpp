#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(int argc,char*argv[]){
	int num;
	string tag;
	char three;
	string left[3], right[3], result[3];
	set<char> setReal;
	map<string,set<char> > mapFeit;
	map<string,set<char> > mapFeit2;
	set<char> setTmp;
	cin>>num;
	for(int i=0;i<num;++i){
		three = '\0';
		tag = "";
		setReal.clear();
		mapFeit.clear();
		mapFeit2.clear();
		setTmp.clear();
		mapFeit["light"] = setTmp;
		mapFeit["heavy"] = setTmp;
		mapFeit2["light"] = setTmp;
		mapFeit2["heavy"] = setTmp;
		cin>>left[0]>>right[0]>>result[0];
		cin>>left[1]>>right[1]>>result[1];
		cin>>left[2]>>right[2]>>result[2];
		for(int k=0;k<3;++k){
			if(result[k]=="even"){
				for(int j=0;j<left[k].size();++j){
					setReal.insert(left[k][j]);
				}
				for(int j=0;j<right[k].size();++j){
					setReal.insert(right[k][j]);
				}
			}
		}
		for(int k=0;k<3;++k){
			if(result[k]=="up"){
				for(int j=0;j<left[k].size();++j){
					if(setReal.find(left[k][j])==setReal.end()){
						if(mapFeit["light"].find(left[k][j])!=mapFeit["light"].end()){
							mapFeit["light"].erase(left[k][j]);
							setReal.insert(left[k][j]);
						}else if(mapFeit["heavy"].find(left[k][j])!=mapFeit["heavy"].end()){
							if(mapFeit2["heavy"].find(left[k][j])!=mapFeit2["heavy"].end()){
								three = left[k][j];
								tag = "heavy";
						}						
							mapFeit2["heavy"].insert(left[k][j]);
						}else{
							mapFeit["heavy"].insert(left[k][j]);
						}
					}
				}
				for(int j=0;j<right[k].size();++j){
					if(setReal.find(right[k][j])==setReal.end()){
						if(mapFeit["heavy"].find(right[k][j])!=mapFeit["heavy"].end()){
							mapFeit["heavy"].erase(right[k][j]);
							setReal.insert(right[k][j]);
						}else if(mapFeit["light"].find(right[k][j])!=mapFeit["light"].end()){
							if(mapFeit2["light"].find(right[k][j])!=mapFeit2["light"].end()){
								tag = "light";
								three = right[k][j];
						}
							mapFeit2["light"].insert(right[k][j]);
						}else {
							mapFeit["light"].insert(right[k][j]);
						}
					}
				}
			}
			if(result[k]=="down"){
				for(int j=0;j<left[k].size();++j){
					if(setReal.find(left[k][j])==setReal.end()){
						if(mapFeit["heavy"].find(left[k][j])!=mapFeit["heavy"].end()){
							mapFeit["heavy"].erase(left[k][j]);
							setReal.insert(left[k][j]);
						}else if(mapFeit["light"].find(left[k][j])!=mapFeit["light"].end()){
							if(mapFeit2["light"].find(left[k][j])!=mapFeit2["light"].end()){
								tag = "light";
								three = left[k][j];
						}
							mapFeit2["light"].insert(left[k][j]);
						}else {
							mapFeit["light"].insert(left[k][j]);
						}
					}
				}
				for(int j=0;j<right[k].size();++j){
					if(setReal.find(right[k][j])==setReal.end()){
						if(mapFeit["light"].find(right[k][j])!=mapFeit["light"].end()){
							mapFeit["light"].erase(right[k][j]);
							setReal.insert(right[k][j]);
						}else if(mapFeit["heavy"].find(right[k][j])!=mapFeit["heavy"].end()){
							if(mapFeit2["heavy"].find(right[k][j])!=mapFeit2["heavy"].end()){
								tag = "heavy";
								three = right[k][j];
						}
							mapFeit2["heavy"].insert(right[k][j]);
						}else{
							mapFeit["heavy"].insert(right[k][j]);
						}
					}
				}
			}
		}
		set<char>::iterator it;
		if(three!='\0')
			cout << three << " is the counterfeit coin and it is " << tag << "." << endl;
		else if(mapFeit["light"].size()==1){
			it = mapFeit["light"].begin();
			cout << *it << " is the counterfeit coin and it is light." << endl;
		}else if(mapFeit["heavy"].size()==1){
			it = mapFeit["heavy"].begin();
			cout << *it << " is the counterfeit coin and it is heavy." << endl;
		}
		else if(mapFeit2["light"].size()==1){
			it = mapFeit2["light"].begin();
			cout << *it << " is the counterfeit coin and it is light." << endl;
		} else if(mapFeit2["heavy"].size()==1){
			it = mapFeit2["heavy"].begin();
			cout << *it << " is the counterfeit coin and it is heavy." << endl;
		}else
			cout << "EEError." << endl;
	}
	return 0;
}
