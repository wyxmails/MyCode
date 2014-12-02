/*Set Matrix Zeroes Total Accepted: 15937 Total Submissions: 51654 My Submissions
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

/*O(n) space solution*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m==0) return;
        int n = matrix[0].size();
        if(n==0) return;
        vector<int> mark(n,0);
        for(int i=0;i<m;++i){
            bool zero = false;
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    zero = true;
                    mark[j] = 1;
                    int tmp = j-1;
                    while(tmp>=0&&matrix[i][tmp]!=0) matrix[i][tmp--] = 0;
                }
            }
            if(zero){
                int tmp = n-1;
                while(tmp>=0&&matrix[i][tmp]!=0) matrix[i][tmp--] = 0;
            }
        }
        for(int j=0;j<n;++j){
            if(mark[j]==0) continue;
            for(int i=0;i<m;++i){
                matrix[i][j] = 0;
            }
        }
    }
};

/*constant space solution*/
class Solution2 {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m==0) return;
        int n = matrix[0].size();
        if(n==0) return;
        bool r0,c0;
        r0=c0=false;
        for(int i=0;i<m;++i){
            if(matrix[i][0]==0){
                c0 = true;
                break;
            }
        }
        for(int j=0;j<n;++j){
            if(matrix[0][j]==0){
                r0 = true;
                break;
            }
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i=1;i<m;++i){
            if(matrix[i][0]==0){
                for(int j=1;j<n;++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j=1;j<n;++j){
            if(matrix[0][j]==0){
                for(int i=1;i<m;++i)
                    matrix[i][j] = 0;
            }
        }
        if(r0){
            for(int j=0;j<n;++j)
                matrix[0][j] = 0;
        }
        if(c0){
            for(int i=0;i<m;++i)
                matrix[i][0] = 0;
        }
    }
};
