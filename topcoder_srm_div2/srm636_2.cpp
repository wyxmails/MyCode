/*
 Problem Statement
     
 Everyone likes some sequences more than others. Every person has their own function which tells them how good a sequence is. For example, for some people this function could simply be the count of negative numbers in the sequence.
  
 Jezalb's most favorite sequences are ones that are sorted in increasing order. When he sees a sequence S, he immediately calculates the number of pairs of indexes i < j such that S[i] < S[j]. He calls this number the "sortedness" of S.
  
 This morning Jezalb entered a classroom and saw a permutation of 1 through N on the blackboard. He quickly calculated its sortedness. He then left the classroom and forgot the permutation. He only remembered the sortedness he computed. You are given this value in a int sortedness.
  
 Later that day Jezalb reentered the classroom and saw a sequence on the blackboard. The sequence was a permutation of 1 through N, but with some elements erased. You are given this sequence as a vector <int> seq with N elements. Some of the elements in seq may be 0, which indicates an erased number.
  
 Jezalb thinks that the sequence seq may have been obtained by erasing some elements of the sequence he saw during his first visit to the classroom. He would like to restore the erased elements.
  
 You are given the int sortedness and the vector <int> seq. Return the number of ways in which he can fill in the missing elements into seq in such a way that the sortedness of the obtained permutation will be exactly sortedness.
 Definition
     
Class:
SortishDiv2
Method:
ways
Parameters:
int, vector <int>
Returns:
int
Method signature:
int ways(int sortedness, vector <int> seq)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
sortedness will be between 0 and 1,000,000,000, inclusive. 
-
seq will contain between 1 and 100 elements, inclusive. 
-
Elements in seq will be between 0 and number of elements in seq, inclusive. 
-
Positive elements in seq will be distinct. 
-
Number of elements equal to 0 in seq will be between 0 and 5, inclusive.
Examples
0)

    
5
{4, 0, 0, 2, 0}
Returns: 2
There are six ways to fill in the missing elements. Out of those six permutations, only two have sortedness 5: {4, 1, 5, 2, 3} and {4, 3, 1, 2, 5}.
1)

    
4
{0, 0, 0, 0}
Returns: 5
All 5 possible ways are: {1, 3, 4, 2}, {1, 4, 2, 3}, {2, 1, 4, 3}, {2, 3, 1, 4}, {3, 1, 2, 4}.
2)

    
2
{1, 3, 2}
Returns: 1
There are no gaps and sortedness is indeed equal to 2.
3)

    
2
{1, 2, 0, 5, 0, 0}
Returns: 0
Regardless of how he fills in the gaps, the sortedness of the resulting permutation will always be greater than 2.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class SortishDiv2{
public:
	int ways(int sortedness, vector <int> seq);
private:
	int GetAll(vector<int> &vec,int &max_round,vector<int> &seq,vector<int> zero_index);
	int CountPair(vector<int> seq);
	int target;
};

int SortishDiv2::CountPair(vector<int> seq){
	int sum = 0;
	for(int i=1;i<seq.size();++i){
		for(int j=i-1;j>=0;--j)
			if(seq[i]>seq[j]) sum++;
	}
	return sum;
}

int SortishDiv2::GetAll(vector<int> &vec,int &max_round,vector<int> &seq,vector<int> zero_index){
	if(max_round==0) return 0;
	for(int i=0;i<zero_index.size();++i)
		seq[zero_index[i]] = vec[i];
	int sum = CountPair(seq);
	max_round--;
	next_permutation(vec.begin(),vec.end());
	int res = GetAll(vec,max_round,seq,zero_index);
	if(sum==target) return res+1;
	else return res;
}

int SortishDiv2::ways(int sortedness, vector <int> seq){
	int n = seq.size();
	if(n<=1) return sortedness==0;
	target = sortedness;
	set<int> left;
	for(int i=0;i<n;++i)
		left.insert(i+1);
	vector<int> zero_index;
	int sum = 0;
	for(int i=0;i<n;++i){
		if(seq[i]==0){
			zero_index.push_back(i);
			continue;
		}else left.erase(seq[i]);
		for(int j=i-1;j>=0;--j){
			if(seq[j]==0) continue;
			if(seq[j]<seq[i]) sum++;
		}
	}
	if(sum>sortedness) return 0;
	int m = left.size();
	if(zero_index.size()!=m) return 0;
	if(m==0) return sortedness==sum;
	vector<int> vec;
	set<int>::iterator it = left.begin();
	for(;it!=left.end();++it){
		vec.push_back(*it);
	}
	int max_round = 1;
	for(int i=1;i<=m;++i) max_round *= i;
	return GetAll(vec,max_round,seq,zero_index);
}

int main(int argc,char*argv[]){
	int arr[] = {4, 0, 0, 2, 0};
	int target = 5;
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vec;
	for(int i=0;i<n;++i)
		vec.push_back(arr[i]);
	SortishDiv2 sd;
	cout << sd.ways(target,vec) << endl;
	return 0;
}
