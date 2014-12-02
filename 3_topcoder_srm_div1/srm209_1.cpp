/*
 Problem Statement
     
 The Olympic Games in Athens end tomorrow. Given the results of the olympic disciplines, generate and return the medal table.  The results of the disciplines are given as a vector <string> results, where each element is in the format "GGG SSS BBB". GGG, SSS and BBB are the 3-letter country codes (three capital letters from 'A' to 'Z') of the countries winning the gold, silver and bronze medal, respectively.  The medal table is a vector <string> with an element for each country appearing in results. Each element has to be in the format "CCO G S B" (quotes for clarity), where G, S and B are the number of gold, silver and bronze medals won by country CCO, e.g. "AUT 1 4 1". The numbers should not have any extra leading zeros. Sort the elements by the number of gold medals won in decreasing order. If several countries are tied, sort the tied countries by the number of silver medals won in decreasing order. If some countries are still tied, sort the tied countries by the number of bronze medals won in decreasing order. If a tie still remains, sort the tied countries by their 3-letter code in ascending alphabetical order.
 Definition
     
Class:
MedalTable
Method:
generate
Parameters:
vector <string>
Returns:
vector <string>
Method signature:
vector <string> generate(vector <string> results)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
results contains between 1 and 50 elements, inclusive.
-
Each element of results is formatted as described in the problem statement.
-
No more than 50 different countries appear in results.
Examples
0)

    
{"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}
Returns: 
{ "KOR 3 1 0",
"ITA 1 0 0",
"TPE 0 1 1",
"CHN 0 1 0",
"JPN 0 1 0",
"AUS 0 0 1",
"GBR 0 0 1",
"UKR 0 0 1" }
These are the results of the archery competitions.
1)

    
{"USA AUT ROM"}
Returns: { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }

2)

    
{"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}
Returns: { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

struct CountryMedal{
	string country;
	int G;
	int S;
	int B;
	CountryMedal(){}
	CountryMedal(string ctry,int G,int S,int B):country(ctry),G(G),S(S),B(B){}
};

class MedalTable{
public:
	vector <string> generate(vector <string> results);
};


bool cmp(const CountryMedal c1,const CountryMedal c2){
	if(c1.G==c2.G){
		if(c1.S==c2.S){
			if(c1.B==c2.B){
				return c1.country<c2.country;
			}else return c1.B>c2.B;
		}else return c1.S>c2.S;
	}else return c1.G>c2.G;
}

vector<string> MedalTable::generate(vector <string> results){
	int n = results.size();
	map<string,CountryMedal> countries;
	for(int i=0;i<n;++i){
		int p1 = results[i].find_first_of(' ');
		int p2 = results[i].find_last_of(' ');
		string country_gold = results[i].substr(0,p1);
		string country_silver = results[i].substr(p1+1,p2-p1-1);
		string country_bronze = results[i].substr(p2+1);
		auto it = countries.find(country_gold);
		if(it!=countries.end()) it->second.G++;
		else countries[country_gold] = CountryMedal(country_gold,1,0,0);
		it = countries.find(country_silver);
		if(it!=countries.end()) it->second.S++;
		else countries[country_silver] = CountryMedal(country_silver,0,1,0);
		it = countries.find(country_bronze);
		if(it!=countries.end()) it->second.B++;
		else countries[country_bronze] = CountryMedal(country_bronze,0,0,1);
	}
	vector<CountryMedal> vec;
	for(auto it = countries.begin();it!=countries.end();++it)
		vec.push_back(it->second);
	sort(vec.begin(),vec.end(),cmp);
	vector<string> res;
	n = vec.size();
	for(int i=0;i<n;++i){
		string tmp = vec[i].country;
		stringstream ss;
		string str;
		ss.clear();
		ss<<vec[i].G;
		ss>>str;
		tmp += ' '+str;
		ss.clear();
		ss<<vec[i].S;
		ss>>str;
		tmp += ' '+str;
		ss.clear();
		ss<<vec[i].B;
		ss>>str;
		tmp += ' '+str;
		res.push_back(tmp);
	}
	return res;
}
