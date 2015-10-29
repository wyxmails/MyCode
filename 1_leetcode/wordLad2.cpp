#include <iostream>
#include <vector>
//#include <unordered_set>  //used in c++11
//#include <unordered_map>  //used in c++11
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
/*
 Given two words (start and end), and a dictionary, 
 find all shortest transformation sequence(s) from start to end, such that:
 
 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,
 
Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 Return
   [
     ["hit","hot","dot","dog","cog"],
     ["hit","hot","lot","log","cog"]
   ]
Note:
 All words have the same length.
 All words contain only lowercase alphabetic characters.
 */
class Solution {
public:
	vector<vector< string > > findLadders(string start, string end, set< string > &dict) {
	map<string,vector<string> > traces;
	vector<string> vectmp;
	traces[start] = vectmp;
	traces[end] = vectmp;
	vector<set<string> > layers(2);
	int cur = 0;
	int pre = 1;
	layers[0].insert(start);
	set<string>::iterator itus;
	while(true){
		cur = !cur;
		pre = !pre;
		for(itus=layers[pre].begin();itus!=layers[pre].end();++itus)
			dict.erase(*itus);
		layers[cur].clear();
		for(itus=layers[pre].begin();itus!=layers[pre].end();++itus){
			for(int i=0;i<(*itus).size();++i){
				string word = *itus;
				int stop = int(word[i]-'a');
				for(int j=(stop+1)%26;j!=stop;j=(j+1)%26){
					word[i] = char('a'+j);
					if(dict.find(word)!=dict.end()){
						traces[word].push_back(*itus);
						layers[cur].insert(word);
					} 
				}
			}
		}
		if(layers[cur].size()==0) return pathes;
		if(layers[cur].count(end)>0) break;
	}
	vector<string> path;
	buildPath(traces,path,end);
	return pathes;
	}
private:
	vector<vector<string> > pathes;
	void buildPath(map<string,vector<string> > &traces, vector<string> &path, const string &word){
		if(traces[word].size()==0){
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(),curPath.end());
			pathes.push_back(curPath);
			path.pop_back();
			return;
		}
		const vector<string> &vectmp = traces[word];
		path.push_back(word);
		for(int i=0;i<vectmp.size();++i){
			buildPath(traces,path,vectmp[i]);
		}
		path.pop_back();
	}
};
int main(int argc,char*argv[]){
	Solution sol;
	string start = "a";
	string end = "c";
	set<string> dict;
	dict.insert("b");
	dict.insert(start);
	dict.insert(end);
	vector<vector<string> > res = sol.findLadders(start,end,dict);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}

}
