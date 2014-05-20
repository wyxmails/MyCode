#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	int ph, em, it, day;
	int daynum, casenum=0;
	cin>>ph>>em>>it>>day;
	while(ph!=-1&&em!=-1&&it!=-1&&day!=-1){
		casenum++;
		daynum = day + 1;
		while((daynum-ph)%23||(daynum-em)%28||(daynum-it)%33){
			daynum++;
		}
		daynum -= day;
		cout << "Case " << casenum << ": the next triple peak occurs in " << daynum << " days." << endl;
		cin>>ph>>em>>it>>day;
	}
	return 0;
}
