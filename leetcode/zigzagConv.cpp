/*ZigZag Conversion
   The string "PAYPALISHIRING" is written in a zigzag pattern on 
   a given number of rows like this: (you may want to display 
   this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string 
 and make this conversion given a number of rows:
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
string convert(string s, int nRows) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function 
	if(nRows==1) return s;
	string res[nRows];
	int index;
	for(int i=0;i<s.size();++i){
		index = i%(2*nRows-2);
		if(index>(nRows-1)) index = 2*nRows-2-index;
		res[index] += s[i];
	}
	string fin = "";
	for(int i=0;i<nRows;++i){
		fin += res[i];
	}
	return fin;
}

class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> vec(nRows,"");
        int n = s.size();
        int c=0,i=0;
        while(i<n){
            for(int j=0;j<nRows&&i<n;++j)
                vec[j] += s[i++];
            for(int j=nRows-2;j>0&&i<n;--j)
                vec[j] += s[i++];
        }
        string res = "";
        for(i=0;i<nRows;++i)
            res += vec[i];
        return res;
    }
};
