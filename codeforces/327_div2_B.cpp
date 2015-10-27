/*
Sample test(s)
input
6 1
police
p m
output
molice
input
11 6
abacabadaba
a b
b c
a d
e g
f a
b b
output
cdcbcdcfcdc
*/

#include <cstdio>                                                                                    
#include <iostream>
using namespace std;

#define MAXN 200010

int main(int argc,char*argv[]){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        char str[MAXN];
        scanf("%s",str);
        int mark[26];
        for(int i=0;i<26;++i){
            mark[i] = i;
        }
        char p[10],q[10];
        while(m>0){
            m--;
            scanf("%s%s",p,q);
            if(p[0]==q[0]) continue;
            for(int i=0;i<26;++i){
                if((p[0]-'a')==mark[i]) mark[i] = q[0]-'a';
                else if((q[0]-'a')==mark[i]) mark[i] = p[0]-'a';
            }
        }
        for(int i=0;i<n;++i){
            str[i] = mark[str[i]-'a']+'a';
        }
        printf("%s\n",str);
    }
    return 0;
}   
