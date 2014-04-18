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
