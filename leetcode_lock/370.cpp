/*
370. Range Addition  QuestionEditorial Solution  My Submissions
Total Accepted: 3146 Total Submissions: 6269 Difficulty: Medium
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:
Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
Hint:

Thinking of using advanced data structures? You are thinking it too complicated.Show More Hint 
*/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length+1,0);
        for(int i=0;i<updates.size();++i){
            res[updates[i][0]] += updates[i][2];
            res[updates[i][1]+1] -= updates[i][2];
        }
        int sum=res[0];
        for(int i=1;i<length;++i){
            sum += res[i];
            res[i] = sum;
        }
        res.resize(length);
        return res;
    }
};
