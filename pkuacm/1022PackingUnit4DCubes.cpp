#include <iostream>
using namespace std;

int product[101][8];
int list[101];
int sides[8];
int maxsides[8];

bool dfs(int row,int col,int val,int &connection, int n){
	connection--;
	product[row][col] = 0;
	for(int i=0;i<8;++i){
		if(sides[i]>maxsides[i])
			maxsides[i] = sides[i];
	}
	if(0==connection) return true;
	if(col%2){
		for(int k=1;k<=n;++k){
			if(0==product[val][col-1]||list[k]==product[val][col-1]&&k!=row){
				product[val][col-1] = 0;
				return false;
			}
		}
		product[val][col-1] = 0;
		connection--;
	}else{
		for(int k=1;k<=n;++k){
			if(0==product[val][col+1]||list[k]==product[val][col+1]&&k!=row){
				product[val][col+1] = 0;
				return false;
			}
		}

		product[val][col+1] = 0;
		connection--;
	}
	row = val;
	for(col=0;col<8;col++){
		val = product[row][col];
		if(val){
				sides[col]++;
				if(col%2) sides[col-1]--;
				else sides[col+1]--;
				for(int k=1;k<=n;++k){
					if(list[k]==val){
						val = k;
						break;
					}
				}
				if(!dfs(row,col,val,connection,n)){
					return false;
				}
				sides[col] --;
				if(col%2) sides[col-1]++;
				else sides[col+1]++;
		}
	}
	return true;
}

int main(int argc,char*argv[]){
	int t,n,number,connection,tmp,side,index,mark;
	bool flag;
	cin>>t;
	while(t){
		connection = 0;
		cin>>n;
		for(int i=0;i<101;++i){
			for(int j=0;j<8;++j){
				product[i][j] = 0;
			}
		}
		for(int i=0;i<101;++i){
			list[i] = 0;
		}
		for(int i=0;i<8;++i){
			sides[i] = 0;
			maxsides[i] = 0;
		}
		for(int i=1;i<=n;++i){
			cin>>list[i];
			for(int j=0;j<8;++j){
				cin>>product[i][j];
				if(product[i][j]) connection++;
			}
		}
		flag = true;
		for(int col=0;col<8;col++){
			//cout << "j: " << j << endl;
			tmp = product[1][col];
			if(tmp){
				//cout << tmp << endl;
				sides[col] ++;
				if(col%2) sides[col-1]--;
				else	sides[col+1]--;
				for(int k=1;k<=n;++k){
					if(list[k]==tmp){
					   tmp = k;
					   break;
					}
				}
				if(!dfs(1,col,tmp,connection,n)){
					flag = false;
					break;
				}
				sides[col]--;
				if(col%2) sides[col-1]++;
				else	sides[col+1]++;
			}
		}
		if(flag&&0==connection){
			int sum = 1;
			for(int k=0;k<8;k+=2){
				//cout << "max: " << maxsides[k] << endl;
				sum *= (maxsides[k]+maxsides[k+1]+1);
			}
			cout << sum << endl;
		}else{
			cout << "Inconsistent" << endl;
		}
		t--;
	}
	return 0;
}
