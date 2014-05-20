#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=22;
int n;
bool relation[MAX][MAX],in[MAX];
map<string,int> hash,criname;
int main(int argc,char*argv[]){
	char ss[MAX];
	cout << "size: " << sizeof(in) << " " << sizeof(relation) << endl;
	//init
	memset(in,false,sizeof(in));
	memset(relation,true,sizeof(relation));
	//read in
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s",ss);
		hash[ss] = i+1;
	}
	count=0;
	while(scanf("%s",ss)&&ss[0]!='Q'){
		if(ss[0]=='E'){
			scanf("%s",ss);
			if(criname[ss]==0){
				criname[ss]	= count+1;
				count++;
				in[count] = true;
			}
		}else if(ss[0]=='M'){
			scanf("%s",ss);
			for(int i=1;i<=n;++i){
				if(in[i]==false){
					relation[hash[ss].second][i] = false;
				}
			}
		}else{
			scanf("%s",ss);
			in[criname[ss].second] = false;
		}
	}
	//process
	for(map<string,int>::iterator it=criname.begin();it!=criname.end();++it){
		for(int i=1;i<=n;++i){
			if(relation[i][(*it).second]){
				//xiong ya li???	
				
			}
		}
	}
	return 0;
}
