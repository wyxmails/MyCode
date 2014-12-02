/*
Decode Ways Total Accepted: 14753 Total Submissions: 92019 My Submissions
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        if(n==0) return n;
        int c[n+1];
        c[0] = 1;
        for(int i=1;i<=n;++i){
            int c1 = 0;
            if(s[i-1]!='0') c1 = c[i-1];
            int c2 = 0;
            if(i>=2&&(s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<='6')) 
                c2 = c[i-2];
            c[i] = c1+c2;
        }
        return c[n];
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0||s[0]=='0') return 0;
        int f1=1,f2=1;
        for(int i=1;i<n;++i){
            int tmp;
            if(s[i]=='0'){
                if(s[i-1]=='0'||s[i-1]-'0'>2) return 0;
                tmp = f1;
            }else if(s[i-1]=='0') tmp = f1;
            else if(s[i-1]-'0'<2||(s[i-1]-'0'==2&&s[i]-'0'<=6)) tmp = f2+f1;
            else tmp = f2;
            f1 = f2;
            f2 = tmp;
        }
        return f2;
    }
};
