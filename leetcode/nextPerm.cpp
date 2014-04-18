/*Next Permutation
 Implement next permutation, which rearranges numbers into 
 the lexicographically next greater permutation of numbers.
 If such arrangement is not possible, it must rearrange it 
 as the lowest possible order (ie, sorted in ascending order).
 The replacement must be in-place, do not allocate extra memory.
 Here are some examples. Inputs are in the left-hand column 
 and its corresponding outputs are in the right-hand column.
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 */
void nextPermutation(vector<int> &num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	bool perm = false;
	int tmp,j,i=num.size()-1;
	j = i;
	//find the first ascender
	while(i>0&&num[i-1]>=num[i]){
		i--;
	}
	int pos = i;
	//find the minimum bigger one
	if(i){
		tmp = num[i-1];
		while(i<num.size()&&tmp<num[i]) i++;
		j = i-1;
	}
	//exchange
	if(pos){
		tmp = num[pos-1];
		num[pos-1] = num[j];
		num[j] = tmp;
	}
	//reverse all the element behind this element
	i = pos;
	j = num.size()-1;
	while(i<j){
		tmp = num[i];
		num[i] = num[j];
		num[j] = tmp;
		i++;
		j--;
	}
}
