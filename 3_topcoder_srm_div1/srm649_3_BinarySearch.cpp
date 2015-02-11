/*

Problem Statement
    
You have one or more sequences of shopping carts. You are given the lengths of these sequences in a vector <int> a. You are going to remove all the shopping carts.  The process of removing the carts will consist of one or more turns. Each turn will take exactly one minute. At the beginning of each turn, you will have some sequences of carts. For each of those sequences you can choose between two options:
split it (in an arbitrary place) into two shorter sequences
remove one shopping cart from the sequence
  There is one additional constraint: during the entire process you can only choose to split a sequence at most b times.  You are given vector <int> a and int b. Compute and return the smallest number of minutes in which it is possible to remove all the carts.
Definition
    
Class:
CartInSupermarket
Method:
calcmin
Parameters:
vector <int>, int
Returns:
int
Method signature:
int calcmin(vector <int> a, int b)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
The number of elements in a will be between 1 and 50, inclusive. 
-
Each element in a will be between 1 and 1,000,000,000, inclusive. 
-
b will be between 0 and 1,000,000,000, inclusive.
Examples
0)

    
{8}
3
Returns: 4
We have a single sequence of 8 carts and we can use at most 3 splits. The optimal solution takes 4 minutes. During the first minute split the sequence of 8 carts into two sequences with 4 carts each. During the second minute perform two splits, dividing each of the two 4-cart sequences into two new sequences with 2 carts each. Thus, after the second minute you will have four sequences of 2 carts. In the third minute choose to remove a cart from each of them. Repeat that choice in the fourth minute and you are done.
1)

    
{6,6,5}
3
Returns: 4
One optimal solution with only 4 minutes looks as follows:
Split each of the first two sequences from 6 to 3+3. Remove a cart from the third sequence, shortening it from 5 to 4. Sequences after the first minute: {3,3,3,3,4}.
Shorten each of the sequences of length 3. Split the sequence of length 4 into 2+2. Sequences after the second minute: {2,2,2,2,2,2}.
Shorten each sequence. Sequences after the third minute: {1,1,1,1,1,1}.
Shorten each sequence again and you are done.
2)

    
{12,5,6,2,6,8}
4
Returns: 6

3)

    
{15,20,11,13,18,24,25,21,22,10,15,14,19}
0
Returns: 25

4)

    
{671122748,846444748,84701624,608579554,672060899,967957440,31438849,734849843,376589643,904285209
,80693344,211737743,85405464,444633541,293184188,935462519,146753109,972886045,496631016,601669536
,257574086,958464570,6294570,546189534,668105964,601197313,784337929,921840143,70408284,722040626
,253400894,56411549,811940644,152086353,122638884,776352066,118932182,177589709,538122558,127914469
,523761221,290027568,734517444,819458123,699130727,784698122,810265337,283326309,593596316,368671876}
6478
Returns: 3805054

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/


//use binary search two times
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CartInSupermarket{
public:
	int calcmin(vector <int> a, int b){
		int l=0,r=*max_element(a.begin(),a.end());
		if(b==0||r<=1) return r;
		//binary search
		while(l<r){
			int m = l + (r-l)/2;
			if(OK(a,b,m)) r = m;
			else l = m+1;
		}
		return r;
	}
	bool OK(vector<int>& a,int b,int maxi){
		int sp = 0;
		for(int i=0;i<a.size();++i){
			if(a[i]>maxi){
				int spl=0;
				if(!getMinSplit(a[i],maxi,spl,b)) return false;
				sp += spl;
			}
		}
		return sp<=b;
	}
	bool getMinSplit(int n,int maxi,int&spl,int max_cuts){
		long long l=max(0,n/maxi-1),r=max_cuts;
		//binary search
		while(l<=r){
			long long cut = (l+r)/2;
			long long reach = 1;
			long long minutes=maxi;
			long long left_cuts = cut;
			//each time the groups double, so need double cuts
			while(left_cuts>=reach&&minutes>0){
				left_cuts -= reach;
				reach *= 2;
				minutes--;
			}
			if(minutes<=0||(left_cuts>0&&minutes==1)) r = cut-1;
			else{
			//if the left_cuts is insufficient, 
			//we can generate 2*left_cuts groups of minutes-1
			//because as we cut the left_cuts groups, other groups will minus 1
			//so, the new generated 2*left_cuts groups have at most minutes-1
			//at the same time, the original reach should minus left_cuts,
			//because we use left_cuts groups of the reach groups
				reach -= left_cuts;
				long long res = minutes*reach+2*left_cuts*(minutes-1);
				if(res<n) l = cut+1;
				else {r = cut; if(l==r) break;}
			}
		}
		if(l!=r) return false;
		spl = r;
		return true;
	}
};
