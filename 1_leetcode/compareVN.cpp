/*
Compare Version Numbers Total Accepted: 840 Total Submissions: 6069 My Submissions Question Solution 
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        int start=0,tmp;
        for(int i=0;i<=version1.size();++i){
            if(i==version1.size()||version1[i]=='.'){
                stringstream ss(version1.substr(start,i-start));
                ss>>tmp;
                v1.push_back(tmp);
                start = i+1;
            }
        }
        start=0;
        for(int i=0;i<=version2.size();++i){
            if(i==version2.size()||version2[i]=='.'){
                stringstream ss(version2.substr(start,i-start));
                ss>>tmp;
                v2.push_back(tmp);
                start = i+1;
            }
        }
        int m = v1.size();
        int n = v2.size();
        for(int i=0;i<m&&i<n;++i){
            if(v1[i]>v2[i]) return 1;
            if(v1[i]<v2[i]) return -1;
        }
        if(m>n){
            for(int i=n;i<m;++i) if(v1[i]>0) return 1;
        }
        if(m<n){
            for(int i=m;i<n;++i) if(v2[i]>0) return -1;
        }
        return 0;
    }
};
