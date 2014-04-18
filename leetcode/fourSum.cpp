/*
   Given an array S of n integers, are there elements a, b, c, 
   and d in S such that a + b + c + d = target? 
   Find all unique quadruplets in the array which gives the sum of target.
Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
 (ie, a ? b ? c ? d)
 The solution set must not contain duplicate quadruplets.
     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
     A solution set is:
     (-1,  0, 0, 1)
     (-2, -1, 1, 2)
     (-2,  0, 0, 2)
 */
vector<vector<int> > fourSum(vector<int> &num, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > vecres;
	vecres.clear();
	if(num.size()<4) return vecres;
	sort(num.begin(),num.end());
	set<vector<int> > setres;
	setres.clear();
	vector<int> vectmp;
	int tmp;
	for(int i=0;i<num.size()-3;++i){
		for(int j=i+1;j<num.size()-2;++j){
			for(int k=j+1,m=num.size()-1;k<m;){
				tmp = num[i]+num[j]+num[k]+num[m];
				if(tmp==target){
					vectmp.clear();
					vectmp.push_back(num[i]);
					vectmp.push_back(num[j]);
					vectmp.push_back(num[k]);
					vectmp.push_back(num[m]);
					setres.insert(vectmp);
					k++;
					m--;
				}else if(tmp>target) m--;
				else k++;
			}
		}
	}
	set<vector<int> >::iterator it;
	for(it=setres.begin();it!=setres.end();++it){
		vecres.push_back(*it);
	}
	return vecres;
}
