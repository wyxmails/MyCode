/*Anagram: Different words containing same letters.
  eg., ATE, TEA, EAT
  You are given the entire English dictionary. You need to find/group the anagrams in the dictionary.
  Do remember the size of the dictionary is huge. So your goal has to be to optimize the comparisons/sorting/findings/…..etc..,
   */
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

map<string,string> dicmap;
void wsort(const string word,string &keyw){
	keyw = word;
	for(int i=0;i<keyw.size();++i){
		for(int j=0;j<keyw.size()-i-1;++j){
			if(keyw[j]>keyw[j+1]){
				char tmp = keyw[j];
				keyw[j] = keyw[j+1];
				keyw[j+1] = tmp;
			}
		}
	}
}

void buildIndex(string file){
	ifstream ifs(file.c_str());
	string word,keyw;
	while(getline(ifs,word)){
		wsort(word,keyw);
		if(dicmap[keyw]=="") dicmap[keyw] = word;
		else dicmap[keyw] += ", " + word;
	}
}

string getAnag(string word){
	string keyw;
	wsort(word,keyw);
	return dicmap[keyw];
}
int main(int aa,char*mm[]){
	if(aa!=2){
		cerr << "Usage: " << mm[0] << " dicfile" << endl;
		return -1;
	}
	string word;
	string file = mm[1];
	buildIndex(file);
	while(cin>>word){
		cout << "anagrams: " <<  getAnag(word) << endl;
	}
	return 0;
}
