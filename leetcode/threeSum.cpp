/*
   Given an array S of n integers, 
   are there elements a, b, c in S such that a + b + c = 0? 
   Find all unique triplets in the array which gives the sum of zero.
Note:
 Elements in a triplet (a,b,c) must be in non-descending order. 
 (ie, a ? b ? c)
 The solution set must not contain duplicate triplets.
     For example, given array S = {-1 0 1 2 -1 -4},
     A solution set is:
     (-1, 0, 1)
     (-1, -1, 2)
 */
vector<vector<int> > threeSum(vector<int> &num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > vecres;
	vecres.clear();
	if(num.size()<3) return vecres;
	sort(num.begin(),num.end());
	vector<int> vectmp;
	set<vector<int> > setres;
	int i,j,k,tmp;
	for(i=0;i<num.size()-2;++i){
		for(j=i+1,k=num.size()-1;j<k;){
			tmp = num[i]+num[j]+num[k];
			if(tmp==0){
				vectmp.clear();
				vectmp.push_back(num[i]);
				vectmp.push_back(num[j]);
				vectmp.push_back(num[k]);
				setres.insert(vectmp);
				j++;
				k--;
			}else if(tmp<0) j++;
			else k--;
		}
	}
	set<vector<int> >::iterator it;
	for(it=setres.begin();it!=setres.end();++it){
		vecres.push_back(*it);
	}
	return vecres;
}
