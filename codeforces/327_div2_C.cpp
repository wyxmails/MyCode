/*
Sample test(s)
input
4
0 0 1 1
output
0
0 0 1 1
input
5
0 1 0 1 0
output
2
0 0 0 0 0
Note
In the second sample the stabilization occurs in two steps: 01010->00100->00000,
and the sequence 00000 is obviously stable.
*/

#include <cstdio>                                                                                                            
#include <iostream>
#include <vector>

#define MAXN 500010

using namespace std;


int main(int argc,char*argv[]){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    vector<int> copy = arr;
    int l=0,r;
    int res=0;
    while(l+1<n){
        while(l<n&&arr[l]==arr[l+1]) l++;
        r=l+1;
        while(r+1<n&&arr[r]!=arr[r+1]) r++;
        res = max(res,(r-l)/2);
        int ll=l+1,rr=r-1;
        while(ll<=rr){
            arr[ll] = arr[ll-1];
            arr[rr] = arr[rr+1];
            ll++;
            rr--;
        }   
        l=r;
    }   
    printf("%d\n",res);
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}   
