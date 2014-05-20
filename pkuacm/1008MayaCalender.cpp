#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char* argv[]){
	string arrayhaab[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
	string arraytzk[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	map<string,int> maphaab;
	for(int i=0;i<19;++i){
		maphaab[arrayhaab[i]] = i*20;
	}
	int items;
	int day,year;
	int date;
	string dot, month;
	cin>>items;
	cout << items << endl;
	for(int i=0;i<items;++i){
		cin>>day>>dot>>month>>year;
		date = day + 1 + maphaab[month] + year*365;
		year = date/260;
		int tempday = date%260;
		if(tempday==0){
			year -= 1;
			month = arraytzk[19];
		}else
			month = arraytzk[(tempday-1)%20];
		day = tempday%13;
		if(day==0)
			day = 13;
		cout << day << " " << month << " " << year << endl;
	}
	return 0;
}
