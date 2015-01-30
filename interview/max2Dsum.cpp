/*
find maximum sum sub matrix of a 2D matrix
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void countPSum(const vector<vector<int> >&vec,vector<vector<int> >&part_sum){
    size_t m = vec.size();
    size_t n=vec[0].size();
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(i>0)
                part_sum[i][j] += part_sum[i-1][j];
            if(j>0)
                part_sum[i][j] += part_sum[i][j-1];
            if(i>0&&j>0)
                part_sum[i][j] -= part_sum[i-1][j-1];
            part_sum[i][j] += vec[i][j];
        }
    }
}

int MaxSum2D(vector<vector<int> > vec){
    int res=0;
    size_t m = vec.size();
    if(m==0) return res;
    size_t n = vec[0].size();
    if(n==0) return res;
    vector<vector<int> > part_sum(m,vector<int>(n,0));
    countPSum(vec,part_sum);
    for(int i=0;i<m;++i){
        for(int i2=i;i2<m;++i2){
            vector<int> bii2(n,0);
            for(int j=0;j<n;++j){
                bii2[j] = part_sum[i2][j];
                if(i>0) bii2[j] -= part_sum[i-1][j];
                if(j>0){
                    bii2[j] -= part_sum[i2][j-1];
                    if(i>0) bii2[j] += part_sum[i-1][j-1];
                }
            }
            int mid=INT_MIN,sum=0;
            for(int j=0;j<n;++j){
                sum += bii2[j];
                mid = max(mid,sum);
                if(sum<0) sum=0;
            }
            res = max(res,mid);
        }
    }
    return res;
}
