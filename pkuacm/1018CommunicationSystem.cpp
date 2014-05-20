#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

int main(int argc,char*argv[]){
	int numcase,numdevice,nummanufacts,band,price;
	set<int> setBand;
	vector<int> vecManufact;
	vector<int> vecNumManufact;
	map<int,int> mapTemp;
	cin >> numcase;
	for(int i=0;i<numcase;++i){
		cin >> numdevice;
		setBand.clear();
		vecManufact.clear();
		vecNumManufact.clear();
		for(int j=0;j<numdevice;++j){
			mapTemp.clear();
			cin >> nummanufacts;
			vecNumManufact.push_back(nummanufacts);
			for(int k=0;k<nummanufacts;++k){
				cin >> band >> price;
				setBand.insert(band);
				mapTemp[(band+price)*100 + k] = price;
			}
			for(map<int,int>::iterator it=mapTemp.begin();it!=mapTemp.end();++it){
				//cout << "first: " << (*it).first << " second: " << (*it).second << endl;	
				vecManufact.push_back((*it).first/100-(*it).second);
				vecManufact.push_back((*it).second);
			}
		}
		vector<int>::iterator itNum, it, itStart;
		set<int>::iterator itSet = setBand.begin();
		double maximum = 0.0;
		double sum;
		bool flag;
		for(;itSet!=setBand.end();++itSet){
			flag = false;
			sum = 0.0;
			itNum = vecNumManufact.begin();
			itStart = vecManufact.begin();
			//cout << "setBand size: " << setBand.size() << endl;
			//cout << "vecManufact size: " << vecManufact.size() << endl;
			//cout << "vecNumManufact size: " << vecNumManufact.size() << endl;
			for(;itNum!=vecNumManufact.end();++itNum){
				for(it=itStart;it!=itStart+(*itNum)*2;it=it+2){
					if((*it)>=(*itSet)){
						//cout << "itSet: " << *itSet << " it: " << *it <<endl;
						it++;
						int minist = (*it);
						//cout << "minist: " << minist << endl;
						it += 2;
						while(it!=(itStart+(*itNum)*2+1)){
							if((*it)<minist)
								minist = (*it);
							it += 2;
						}
						//cout << "minist2: " << minist << endl;
						sum += minist;
						break;
					}
				}
				if(it==(itStart+(*itNum)*2))
					flag = true;
				itStart += 2*(*itNum);
				//cout << "*itStart: " << *itStart << " " << *(itStart+1) << endl;
			}
			//cout << "sum: " << sum << endl;
			if(flag)
				sum = 0.0;
			else if(sum!=0.0)
				sum = (double)(*itSet)/sum;
			if(sum>maximum)
				maximum = sum;
			//cout << "max: " << maximum << endl;
		}
		cout << setiosflags(ios::fixed) << setprecision(3) << maximum << endl;
		//cout<<fixed<<setprecision(3)<<maximum<<endl;
		//printf("%.3f\n",maximum);
	}
	return 0;
}
