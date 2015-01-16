#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TheFootballDivTwo{
public:
	int find(int yourScore, vector <int> sc, vector <int> num){
		int n = sc.size();
		vector<pair<int,int> > mark(n);
		int total=0;
		for(int i=0;i<n;++i){
			total += num[i];
			mark[i] = {sc[i],num[i]};
		}
		sort(mark.begin(),mark.end());
		int less=0;
		int i=0;
		for(;i<n;++i){
			if(mark[i].first>yourScore) break;
			less += mark[i].second;
		}
		//if(mark[i].first-yourScore>6) return total-less+1;
		//if(mark[i].second*2>(total+1)) return total-less+1;
		int left = total+1;
		while(i<n&&mark[i].first-yourScore<=6){
			if(mark[i].first-yourScore<=3&&mark[i].second>1){ 
				less += mark[i].second; 
				left -= mark[i].second;
				i++;
				continue;}
			if(mark[i].second*2>=left){
				less += (left/2);
				break;
			}
			less += mark[i].second;
			left -= mark[i].second*2;
			i++;
		}
		return (total-less+1);
	}
};
