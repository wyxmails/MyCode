/*
306. Additive Number My Submissions Question
Total Accepted: 5206 Total Submissions: 21504 Difficulty: Medium
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. 
Except for the first two numbers, 
each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
*/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        n = num.size();
        for(int i=1;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(check(0,i,j,num))
                    return true;
            }
        }
        return false;
    }
    bool check(int f,int s,int end,string num){
        long long l=0,r=0;
        if((num[f]=='0'&&s-f>1)||(num[s]=='0'&&end-s>1)) return false;
        for(int i=f;i<s;++i){
            l = l*10+(num[i]-'0');
        }
        for(int i=s;i<end;++i)
            r = r*10+(num[i]-'0');
        l = l+r;
        r=l;
        int i=end;
        long long e=0;
        while(r>0&&i<n){
            e = e*10+(num[i++]-'0');
            r /= 10;
        }
        if(l==e){
            if(i==n) return true;
            return check(s,end,i,num);
        }else
            return false;
    }
private:
    int n;
};
