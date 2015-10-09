/*
Count Primes My Submissions Question Solution 
Total Accepted: 35178 Total Submissions: 167565 Difficulty: Easy
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        bool isP[n];
        for(int i=2;i<n;++i) isP[i] = true;
        for(int i=2;i*i<=n;++i){
            if(!isP[i]) continue;
            for(int j=i*i;j<n;j+=i)
                isP[j] = false;
        }
        int count = 0;
        for(int i=2;i<n;++i){
            if(isP[i]) count++;
        }
        return count;
    }
};
