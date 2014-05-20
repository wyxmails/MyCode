#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;
int main(int argc,char*argv[]){
	if(2!=argc){
		cerr << "Usage: " << argv[0] << " wordfile." << endl;
		return -1;
	}
	ifstream ifs(argv[1]);
	time_t timer;
	time(&timer);
	string outfile;
	stringstream ss;
	ss << timer;
	ss >> outfile;
	outfile = "unfamiliar." + outfile;
	int pos,right,total=0, correct=0;
	string line,word,chinese;
	vector<string> vecStr;
	int type;
	cout << "En To Ch?enter 1:enter2=";
	cin >> type;
	while(getline(ifs,line)){
		total++;
		pos = line.find_first_of('^');
		word = line.substr(0,pos);
		chinese = line.substr(pos+1,line.size()-pos);
		if(1==type){
			cout << "\033[32mNo." << setiosflags(ios::left) << setw(2) << total << setfill(' ') << "\033[0m" << " ";
			cout << word << "      ";
		}else{
			cout << "\033[32mNo." << setiosflags(ios::left) << setw(2) << total << setfill(' ') << "\033[0m" << " ";
			cout << chinese << "      ";
		}
		cout << "Know?enter 1:enter 0=" ;
		cin >> right;
		if(1==type){
			cout << setw(6) << " ";
		    cout <<  chinese << "     " ;
		}else{
			cout << setw(6) << " ";
			cout << word << "      ";
		}
		if(right){
			cout << "Correct?enter 1:enter 0=";
			cin >> right;
			if(right)
				correct ++;
			else
				vecStr.push_back(line);
				//ofs << word << '^' << chinese << endl;
		}
		else{
			cout << "Remembered?enter 1=";
			cin >> right;
			vecStr.push_back(line);
			//ofs << word << '^' << chinese << endl;
		}
	}
	if(vecStr.size()){
		ofstream ofs(outfile.c_str());
		vector<string>::iterator it=vecStr.begin();
		for(;it!=vecStr.end();++it){
			ofs << *it << endl;
		}
	}

	cout << "You have finished the whole " << total << " words. " << endl;
	if(total!=correct){
		cout << "But includes " << total-correct << " unfamiliar ones." << endl;
		cout << "The Unfamiliar ones are in " << outfile << " ." << endl;
	}
	else{
		cout << "And all are correct. Congratulations!" << endl;
	}
	return 0;
}
