/*Permutations
 Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
vector<vector<int> > permute(vector<int> &num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > res;
	res.clear();
	if(num.size()==0) return res;
	if(num.size()==1){
		res.push_back(num);
		return res;
	}
	vector<int> tmp;
	for(int i=0;i<num.size();++i){
		vector<vector<int> > tmpres;
		tmpres.clear();
		tmp.clear();
		tmp = num;
		tmp.erase(tmp.begin()+i);
		tmpres = permute(tmp);
		for(int j=0;j<tmpres.size();++j){
			res.push_back(tmpres[j]);
			int s=res.size();
			res[s-1].insert(res[s-1].begin(),num[i]);
		}
	}
	return res;
}
