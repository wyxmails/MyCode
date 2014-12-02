/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(1,1);
        for(int i=1;i<=rowIndex;++i){
            for(int j=vec.size()-1;j>0;--j)
                vec[j] += vec[j-1];
            vec.push_back(1);
        }
        return vec;
    }
};
