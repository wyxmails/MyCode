/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        vector<int> vec;
        while(vec.size()<numRows){
            for(int j=vec.size()-1;j>0;--j){
                vec[j] += vec[j-1];
            }
            vec.push_back(1);
            res.push_back(vec);
        }
        return res;
    }
};
