/*
Repeated DNA Sequences Total Accepted: 906 Total Submissions: 5489 My Submissions Question Solution 
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<char,int> mark;
        mark['A'] = 0; mark['C'] = 1; mark['G'] = 2; mark['T'] = 3;
        map<int,char> rmark;
        rmark[0] = 'A'; rmark[1] = 'C'; rmark[2] = 'G'; rmark[3] = 'T';
        map<long long,int> appear;
        vector<string> res;
        int n = s.size();
        if(n<=10) return res;
        long long orig=0;
        for(int i=0;i<10&&i<s.size();++i)
            orig = orig*10 + mark[s[i]];
        appear[orig]++;
        long long rate = pow(10,9);
        for(int i=10;i<s.size();++i){
            orig -= mark[s[i-10]]*rate;
            orig = orig*10 + mark[s[i]];
            appear[orig]++;
        }
        for(auto it=appear.begin();it!=appear.end();++it){
            if(it->second>1){
                string tmp = "";
                long long v = it->first;
                for(int i=0;i<10;++i){
                    tmp = rmark[v%10]+tmp;
                    v /= 10;
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};
