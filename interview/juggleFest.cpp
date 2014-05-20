#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct C{
	int H;
	int E;
	int P;
	string name;
	map<int,string> posJ;
};
struct J{
	int H;
	int E;
	int P;
	int cur;//current positon in pref
	string name;
	vector<pair<string,int> > pref;
};
void getInput(map<string,J> &jvec,map<string,C> &cvec){
	string str,tmpstr;
	J tmpJ;
	C tmpC;
	int i=0,j=0,pos;
	while(cin>>str){
		if(str=="C"){
			cin>>tmpC.name;
			for(int i=0;i<3;++i){
				cin>>tmpstr;
				switch(tmpstr[0]){
					case 'H':
						tmpC.H = atoi(tmpstr.substr(2,tmpstr.size()-2).c_str());
						break;
					case 'E':
						tmpC.E = atoi(tmpstr.substr(2,tmpstr.size()-2).c_str());
						break;
					case 'P':
						tmpC.P = atoi(tmpstr.substr(2,tmpstr.size()-2).c_str());
						break;
				}
			}
			cvec[tmpC.name] = tmpC;
		}else if(str=="J"){
			cin>>tmpJ.name;
			tmpJ.cur=0;
			for(int i=0;i<3;++i){
				cin>>tmpstr;
				switch(tmpstr[0]){
					case 'H':
						tmpJ.H = atoi(tmpstr.substr(2,tmpstr.size()-2).c_str());
						break;
					case 'E':
						tmpJ.E = atoi(tmpstr.substr(2,tmpstr.size()-2).c_str());
						break;
					case 'P':
						tmpJ.P = atoi(tmpstr.substr(2,tmpstr.size()-2).c_str());
						break;
				}
			}
			cin>>tmpstr;
			vector<pair<string,int> > tmpvec;
			tmpvec.clear();
			pos = tmpstr.find_first_of(',');
			while(pos!=string::npos){
				tmpvec.push_back(make_pair(tmpstr.substr(0,pos),0));
				tmpstr = tmpstr.substr(pos+1,tmpstr.size()-pos-1);
				pos = tmpstr.find_first_of(',');
			}
			if(tmpstr.size()) tmpvec.push_back(make_pair(tmpstr,0));
			tmpJ.pref = tmpvec;
			jvec[tmpJ.name] = tmpJ;
		}
	}
}
void compute(map<string,J> &jvec, map<string,C> &cvec){
	map<string,J>::iterator it;
	vector<pair<string,int> >::iterator itvec;
	int score;
	for(it=jvec.begin();it!=jvec.end();++it){
		itvec=(*it).second.pref.begin();
		score = cvec[(*itvec).first].H*(*it).second.H + 
			cvec[(*itvec).first].E*(*it).second.E + cvec[(*itvec).first].P*(*it).second.P;
		cvec[(*itvec).first].posJ[score] = (*it).first;
		(*itvec).second = score;
		itvec++;
		while(itvec!=(*it).second.pref.end()){
			score = cvec[(*itvec).first].H*(*it).second.H +
				cvec[(*itvec).first].E*(*it).second.E + cvec[(*itvec).first].P*(*it).second.P;
			(*itvec).second = score;
			itvec++;
		}
	}
}
void update(map<string,C> &cmap, map<int,vector<string> >& csort){
	map<string,C>::iterator it;
	vector<string> tmpvec;
	for(it=cmap.begin();it!=cmap.end();++it){
		if(csort.find((*it).second.posJ.size())==csort.end()){
			tmpvec.clear();
			tmpvec.push_back((*it).first);
			csort.insert(make_pair((*it).second.posJ.size(),tmpvec));
		}else{
			csort[(*it).second.posJ.size()].push_back((*it).first);
		}
	}
}
int main(int argc,char*argv[]){
	int numJ = 12;//12000;
	int numC = 3;//2000;
	int num = numJ/numC;
	map<string,J> jmap;
	map<string,C> cmap;
	map<int,vector<string> > csort;
	jmap.clear();
	cmap.clear();
	csort.clear();
	cout << "start----" << endl;
	getInput(jmap,cmap);
	cout << "compute----" << endl;
	compute(jmap,cmap);
	cout << "update----" << endl;
	update(cmap,csort);
	map<int,vector<string> >::iterator it;
	vector<string>::iterator iiit;
	map<int,string>::iterator itposj;
	cout << "output----" << endl;
	cout << csort.size() << endl;
	for(it=csort.begin();it!=csort.end();++it){
		cout << "circuit one" << endl;
		cout << (*it).first << " " << (*it).second.size() << endl;
		vector<string>::iterator tmp = (*it).second.begin();
		iiit = (*it).second.begin();
		cout << *iiit << " ";
		itposj = cmap[*iiit].posJ.begin();
		for(int i=0;i<num&&itposj!=cmap[*iiit].posJ.end();++i){
			cout << (*itposj).second << " ";
			for(vector<pair<string,int> >::iterator ittmp=jmap[(*itposj).second].pref.begin();ittmp!=jmap[(*itposj).second].pref.end();++ittmp){
				if(ittmp!=jmap[(*itposj).second].pref.begin()) cout << " ";
				cout << (*ittmp).first << ":" << (*ittmp).second;
			}
			cout << ", ";
			itposj++;
		}
		cout << "ffffffff" << endl; 
		cout << endl;
		while(itposj!=cmap[*iiit].posJ.end()){
			cout << "111" << endl;
			jmap[(*itposj).second].cur += 1;
			int cur = jmap[(*itposj).second].cur;
			string cname = jmap[(*itposj).second].pref[cur].first;
			int score = jmap[(*itposj).second].pref[cur].second;
			int sortpos = cmap[cname].posJ.size();
			cmap[cname].posJ[score] = (*itposj).first;
			cout << "222" << endl;
			for(vector<string>::iterator ittmp = csort[sortpos].begin();
					ittmp!=csort[sortpos].end();++ittmp){
			cout << "333" << endl;
				if(cname.compare(*ittmp)==0){
					csort[sortpos].erase(ittmp);
					break;
				}
			}
			cout << "444" << endl;
			csort[cmap[cname].posJ.size()].push_back(cname);
			itposj++;
		}
		(*it).second.erase(iiit);
		it = csort.begin();
	}
}
