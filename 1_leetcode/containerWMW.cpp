/*Container With Most Water
   Given n non-negative integers a1, a2, ..., an, 
   where each represents a point at coordinate (i, ai). 
   n vertical lines are drawn such that 
   the two endpoints of line i is at (i, ai) and (i, 0). 
   Find two lines, which together with x-axis forms a container, 
   such that the container contains the most water.
Note: You may not slant the container.
 */
int maxArea(vector<int> &height) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int i=0,j=height.size()-1;
	int tmp, water = 0;
	while(i<j){
		if(height[i]<height[j]){
			tmp = height[i]*(j-i);
			if(tmp>water) water = tmp;
			i++;
		}else{
			tmp = height[j]*(j-i);
			if(tmp>water) water = tmp;
			j--;
		}
	}
	return water;
}

int maxArea2(vector<int> &height) {
        int n = height.size();
        if(n==0) return 0;
        int amount = 0; 
        for(int i=0,j=n-1;j>i;){
            int tmp = min(height[i],height[j])*(j-i);
            amount = max(tmp,amount);
            height[i]>height[j]?j--:i++;
        }
        return amount;
}
