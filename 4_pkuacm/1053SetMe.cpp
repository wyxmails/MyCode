#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc,char*argv[]){
	string str;
	int count;
	bool flag,found;
	string strarr[12];
	while(cin>>str){
		found=false;
		strarr[0] = str;
		cout << "CARDS:  " << strarr[0] << " ";
		for(count=1;count<12;++count){
			cin>>strarr[count];
			cout << strarr[count];
			if(count!=11) cout << " ";
		}
		cout << endl;
		cout << "SETS:   ";
		count=1;
		for(int i=0;i<10;++i){
			for(int j=i+1;j<11;++j){
				for(int k=j+1;k<12;++k){
					flag=true;
					for(int num=0;num<4;++num){
						if(strarr[i][num]==strarr[j][num]&&strarr[j][num]==strarr[k][num])
							continue;
						else if(strarr[i][num]!=strarr[j][num]
								&&strarr[j][num]!=strarr[k][num]
								&&strarr[i][num]!=strarr[k][num])
							continue;
						else{
							flag=false;
							break;
						}
					}
					if(flag){
						if(count!=1) cout << setw(9) << count;
						else cout << count;
						cout << ".  " << strarr[i] << " "
							<< strarr[j] << " " << strarr[k] << endl;
						count++;
						found = true;
					}
				}
			}
		}
		if(!found) cout << "*** None Found ***" << endl;
		cout << endl;
	}
	return 0;
}
