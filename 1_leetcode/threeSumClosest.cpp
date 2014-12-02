/*
   Given an array S of n integers, 
   find three integers in S such that 
   the sum is closest to a given number, target. 
   Return the sum of the three integers. 
   You may assume that each input would have exactly one solution.
     For example, given array S = {-1 2 1 -4}, and target = 1.
     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
int threeSumClosest(vector<int> &num, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(num.size()<3) return 0;
	sort(num.begin(),num.end());
	int sum = num[0]+num[1]+num[2];
	int gap = abs(sum-target);
	int tmp;
	for(int i=0;i<num.size()-2;++i){
		for(int j=i+1,k=num.size()-1;j<k;){
			tmp = num[i]+num[j]+num[k];
			if(tmp==target){
				return target;
			}else if(tmp<target){
				if(abs(tmp-target)<gap){
					sum = tmp;
					gap = abs(tmp-target);
				}
				j++;
			}else{
				if(abs(tmp-target)<gap){
					sum = tmp;
					gap = abs(tmp-target);
				}
				k--;
			}
		}
	}
	return sum;
}

int threeSumClosest2(vector<int> &num, int target) {
        int n = num.size();
        int sum = num[0]+num[1]+num[2];
        sort(num.begin(),num.end());
        for(int i=0;i<n-2;++i){
            for(int j=i+1,k=n-1;j<k;){
                int tmp = num[i]+num[j]+num[k];
                if(tmp==target) return target;
                else if(tmp<target){
                    if(abs(tmp-target)<abs(sum-target)) sum = tmp;
                    j++;
                }else{
                    if(abs(tmp-target)<abs(sum-target)) sum = tmp;
                    k--;
                }
            }
        }
        return sum;
}
