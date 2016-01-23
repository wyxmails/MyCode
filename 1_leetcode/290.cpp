/*
290. Word Pattern My Submissions Question Solution 
Total Accepted: 3998 Total Submissions: 14996 Difficulty: Easy
Given a pattern and a string str, find if str follows the same pattern.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
patterncontains only lowercase alphabetical letters, and str contains words separated by a single space. Each word in str contains only lowercase alphabetical letters.
Both pattern and str do not have leading or trailing spaces.
Each letter in pattern must map to a word with length that is at least 1.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> myMap1;
        map<string,char> myMap2;
        int n = pattern.size();
        for(int i=0;i<n;++i){
            if(str.size()<=0) return false;
            int j = str.find_first_of(' ');
            if(j<0) j=str.size();
            string tmp = str.substr(0,j);
            if(j==str.size()) str = "";
            else str = str.substr(j+1);
            auto it1 = myMap1.find(pattern[i]);
            auto it2 = myMap2.find(tmp);
            if(it1!=myMap1.end()&&it2!=myMap2.end()){
                if(it1->second!=tmp||it2->second!=pattern[i]) return false;
            }else if(it1==myMap1.end()&&it2==myMap2.end()){
                myMap1[pattern[i]] = tmp;
                myMap2[tmp] = pattern[i];
            }else return false;
        }
        if(str.size()>0) return false;
        return true;
    }
};
