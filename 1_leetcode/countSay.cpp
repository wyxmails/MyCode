/*Count and Say
   The count-and-say sequence is 
  the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
 */
string countAndSay(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int m,round = 1;
	string s,mid,res;
	char c;
	stringstream ss;
	mid=res="1";
	while(round<n){
		round++;
		res = "";
		for(int i=0;i<mid.size();){
			c = mid[i];
			m = i;
			i++;
			while(i<mid.size()&&mid[i]==c) i++;
			ss.clear();
			m = i-m;
			m = m*10 + c-'0';
			ss<<m;
			ss>>s;
			res += s;
		}
		mid = res;
	}
	return res;
}
string countAndSay2(int n) {
        string res = "1";
        for(int i=1;i<n;++i){
            string tmp = "";
            for(int j=0;j<res.size();++j){
                int cnt = j;
                while(j+1<res.size()&&res[j]==res[j+1]) j++;
                cnt = j-cnt+1;
                //tmp += char('0'+cnt) +res[j]; //wrong answer 2 return b, why?
                tmp = tmp + char('0'+cnt) +res[j];
            }
            res = tmp;
        }
        return res;
}
