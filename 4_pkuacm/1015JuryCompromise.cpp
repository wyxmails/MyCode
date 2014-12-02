//dp problems
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int arrps[210];
int arrds[210];
int f[21][1000];
int path[21][1000];
int result[21];

int cmp(const void*s1,const void*s2){
	return (*(int*)s1)-(*(int*)s2);
}

int main(int argc,char*argv[]){
	int n,m,ps,ds;
	int valZero;
	int count=0;
	int i,j,k,t1,t2;
	while(scanf("%d%d",&n,&m)&&(n+m)){
		count++;
		valZero = 20*m;
		for(i=1;i<=n;++i){
			scanf("%d%d",&arrps[i],&arrds[i]);
		}
		for(i=0;i<2*valZero;++i)
			for(j=0;j<=m;++j)
				f[j][i] = -1;
		f[0][valZero] = 0;
		for(j=0;j<m;++j){
			for(k=0;k<2*valZero;++k){
				if(f[j][k]>=0){
					for(i=1;i<=n;++i){
						if(f[j][k]+arrps[i]+arrds[i]>
								f[j+1][k+arrps[i]-arrds[i]]){
							t1=j;
							t2=k;
							while(t1>0&&path[t1][t2]!=i){
								t2 -= arrps[path[t1][t2]]-arrds[path[t1][t2]];
								t1 -=1;
								
							}
							if(t1==0){
								f[j+1][k+arrps[i]-arrds[i]] = f[j][k]+arrps[i]+arrds[i];
								path[j+1][k+arrps[i]-arrds[i]] = i;
							}
						}
					}
				}
			}
		}
		i=valZero;
		j=0;
		while(f[m][i+j]<0&&f[m][i-j]<0) j++;
		if(f[m][i+j]>f[m][i-j]) k = i+j;
		else k=i-j;
		//cout << "k: " << k << endl;
		//cout << (k-valZero+f[m][k])/2 << " " << (f[m][k]-k+valZero)/2 << endl;
		ps=ds=0;
		for(i=m;i>0;--i){
			//cout << "result[" <<i << "]: " << result[i];
			result[i] = path[i][k];
			ps += arrps[result[i]];
			ds += arrds[result[i]];
			//cout << "ps: " << ps << " ds: " << ds << endl;
			k -= arrps[path[i][k]]-arrds[path[i][k]];
		}
		cout << "Jury #" << count << endl;
		cout << "Best jury has value " << ps << " for prosecution and value " << ds << " for defence: " << endl;
		qsort(result+1, m, sizeof(int), cmp);
		for(i=1;i<=m;++i) cout << " " << result[i];
		cout << endl<<endl;
	}
	return 0;
}
