/*Letter Combinations of a Phone Number
 Given a digit string, 
 return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons)
 is given below.
2:abc, 3:def, 4:ghi, 5:jkl, 6:mno, 7:pqrs, 8:tuv, 0wxyz
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
 Although the above answer is in lexicographical order, 
 your answer could be in any order you want.
 */
vector<string> letterCombinations(string digits) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<string> vecres;
	vecres.clear();
	vector<string> vectmp1,vectmp2,vectmp3;
	vectmp1.clear();
	vectmp2.clear();
	vectmp3.clear();
	int i=0;
	while(digits[i]!='\0'&&(digits[i]-'0'>9||digits[i]-'0'<0)) i++;
	if(i>=digits.size()){
		vecres.push_back(digits);
		return vecres;
	}
	switch(digits[i]){
		case '2':
			digits[i] = 'a';
			vecres = letterCombinations(digits);
			digits[i] = 'b';
			vectmp1 = letterCombinations(digits);
			digits[i] = 'c';
			vectmp2 = letterCombinations(digits);
			break;
		case '3':
			digits[i] = 'd';
			vecres = letterCombinations(digits);
			digits[i] = 'e';
			vectmp1 = letterCombinations(digits);
			digits[i] = 'f';
			vectmp2 = letterCombinations(digits);
			break;
		case '4':
			digits[i] = 'g';
			vecres = letterCombinations(digits);
			digits[i] = 'h';
			vectmp1 = letterCombinations(digits);
			digits[i] = 'i';
			vectmp2 = letterCombinations(digits);
			break;
		case '5':
			digits[i] = 'j';
			vecres = letterCombinations(digits);
			digits[i] = 'k';
			vectmp1 = letterCombinations(digits);
			digits[i] = 'l';
			vectmp2 = letterCombinations(digits);
			break;
		case '6':
			digits[i] = 'm';
			vecres = letterCombinations(digits);
			digits[i] = 'n';
			vectmp1 = letterCombinations(digits);
			digits[i] = 'o';
			vectmp2 = letterCombinations(digits);
			break;
		case '7':
			digits[i] = 'p';
			vecres = letterCombinations(digits);
			digits[i] = 'q';
			vectmp1 = letterCombinations(digits);
			digits[i] = 'r';
			vectmp2 = letterCombinations(digits);
			digits[i] = 's';
			vectmp3 = letterCombinations(digits);
			break;
		case '8':
			digits[i] = 't';
			vecres = letterCombinations(digits);
			digits[i] = 'u';
			vectmp1 = letterCombinations(digits);
			digits[i] = 'v';
			vectmp2 = letterCombinations(digits);
			break;
		case '9':
			digits[i] = 'w';
			vecres = letterCombinations(digits);
			digits[i] = 'x';
			vectmp1 = letterCombinations(digits);
			digits[i] = 'y';
			vectmp2 = letterCombinations(digits);
			digits[i] = 'z';
			vectmp3 = letterCombinations(digits);
			break;
	}
	vecres.insert(vecres.begin(),vectmp1.begin(),vectmp1.end());
	vecres.insert(vecres.begin(),vectmp2.begin(),vectmp2.end());
	vecres.insert(vecres.begin(),vectmp3.begin(),vectmp3.end());
	return vecres;
}
void myCom(vector<string>& res, string digits,string &str,unordered_map<int,vector<char> > dic){
        int d = int(digits[0]-'0');
        int n = str.size();
        if(digits.size()==1){
            for(int i=0;i<dic[d].size();++i){
                str += dic[d][i];
                res.push_back(str);
                str.erase(n,1);
            }
            return;
        }
        string tmp = digits;
        tmp.erase(0,1);
        for(int i=0;i<dic[d].size();++i){
            str += dic[d][i];
            myCom(res,tmp,str,dic);
            str.erase(n,1);
        }
}
vector<string> letterCombinations2(string digits) {
        unordered_map<int,vector<char> > dic;
        dic[2].push_back('a'); dic[2].push_back('b'); dic[2].push_back('c');
        dic[3].push_back('d'); dic[3].push_back('e'); dic[3].push_back('f');
        dic[4].push_back('g'); dic[4].push_back('h'); dic[4].push_back('i');
        dic[5].push_back('j'); dic[5].push_back('k'); dic[5].push_back('l');
        dic[6].push_back('m'); dic[6].push_back('n'); dic[6].push_back('o');
        dic[7].push_back('p'); dic[7].push_back('q'); dic[7].push_back('r'); dic[7].push_back('s');
        dic[8].push_back('t'); dic[8].push_back('u'); dic[8].push_back('v');
        dic[9].push_back('w'); dic[9].push_back('x'); dic[9].push_back('y'); dic[9].push_back('z');
        vector<string> res;
        if(digits.size()==0){
            res.push_back(digits);
            return res;
        } 
        string str = "";
        myCom(res,digits,str,dic);
    }
    
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        mark['2'] = "abc"; mark['3'] = "def";
        mark['4'] = "ghi"; mark['5'] = "jkl";
        mark['6'] = "mno"; mark['7'] = "pqrs";
        mark['8'] = "tuv"; mark['9'] = "wxyz";
        string mid = "";
        vector<string> res;
        myCom(0,digits,mid,res);
        return res;
    }
    void myCom(int index,string digits,string &mid,vector<string>&res){
        if(index>=digits.size()){
            res.push_back(mid);
            return;
        }
        string tmp =mark[digits[index]];
        for(int i=0;i<tmp.size();++i){
            mid += tmp[i];
            myCom(index+1,digits,mid,res);
            mid.resize(mid.size()-1);
        }
    }
private:
        unordered_map<char,string> mark;
};
