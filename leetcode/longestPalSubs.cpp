/*Longest Palindromic Substring
   Given a string S, find the longest palindromic substring in S. 
  You may assume that the maximum length of S is 1000, i
  and there exists one unique longest palindromic substring.*/
string longestPalindrome(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int b=0;
	int e=s.size();
	int i,j;
	string res;
	int MAX = 0;
	for(int b=0;b<s.size();++b){
		for(int e=s.size()-1;e>=b+MAX;--e){
			i=b;
			j=e;
			while(i<j){
				if(s[i]!=s[j])
					break;
				i++;
				j--;
			}
			if(i>=j&&(e-b+1)>MAX){
				res = s.substr(b,e-b+1);
				MAX = res.size();
			}
		}
	}
	return res;
}
bool isP(const string&s,int l,int r){
        while(r>l){
            if(s[r]!=s[l]) return false;
            r--; l++;
        }
        return true;
    }
string longestPalindrome2(string s) {
        int n = s.size();
        if(n<=1) return s;
        vector<int> len(n,1);
        int end = n-2;
        int Max = INT_MIN;
        int begin;
        while(end>=0){
            if(end+len[end+1]+1<n&&s[end]==s[end+len[end+1]+1]){
                len[end] = len[end+1]+2;
                if(len[end]>Max){
                    Max = len[end];
                    begin = end;
                }
            }else{
                for(int i=end+len[end+1];i>end;--i){
                    if(isP(s,end,i)){
                        len[end] = i-end+1;
                        if(len[end]>Max){
                            Max = len[end];
                            begin = end;
                        }
                        break;
                    }
                }
            }
            end--;
        }
        return s.substr(begin,Max);
    }
