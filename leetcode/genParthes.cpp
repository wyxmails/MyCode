/*Generate Parentheses
   Given n pairs of parentheses, 
  write a function to generate all combinations of well-formed parentheses.
 For example, given n = 3, a solution set is:
 "((()))", "(()())", "(())()", "()(())", "()()()"
 */
vector<string> generateParenthesis(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	set<string> setres;
	vector<string> vectmp,vectmp1;
	setres.clear();
	vectmp.clear();
	string str;
	if(n==0) return vectmp;
	if(n==1){
		str = "()";
		vectmp.push_back(str);
		return vectmp;
	}
	vectmp = generateParenthesis(n-1);
	for(int i=0;i<vectmp.size();++i){
		str = "(" + vectmp[i] + ")";
		setres.insert(str);
		str = "()" + vectmp[i];
		setres.insert(str);
		str = vectmp[i] + "()";
		setres.insert(str);
	}
	vectmp.clear();
	vectmp1.clear();
	for(int i=2;i<=n/2;++i){
		vectmp = generateParenthesis(i);
		vectmp1 = generateParenthesis(n-i);
		for(int j=0;j<vectmp.size();++j){
			for(int k=0;k<vectmp1.size();++k){
				str = vectmp[j] + vectmp1[k];
				setres.insert(str);
				str = vectmp1[k] + vectmp[j];
				setres.insert(str);
			}
		}
	}
	vector<string> vecres;
	vecres.clear();
	set<string>::iterator it;
	it = setres.begin();
	while(it!=setres.end()){
		vecres.push_back(*it);
		it++;
	}
	return vecres;
}
