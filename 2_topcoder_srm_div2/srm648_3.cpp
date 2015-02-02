#include <iostream>
#include <algorithm>
using namespace std;

class ABC{
public:
	string createString(int N, int K){
		string res = "";
		int a = N/3;
		int b = (N-a)/2;
		int c = N-a-b;
		int maxi = a*(b+c)+b*c;
		if(maxi<K) return "";
		if(K==maxi){
			res.append(a,'A');
			res.append(b,'B');
			res.append(c,'C');
		}else{
			bool found = false;
			for(a=0;a<N;++a){
				for(b=0;a+b<N;++b){
					for(c=0;a+b+c<N;++c){
						int tmp = a*(b+c)+b*c;
						if(tmp==K){
							found = true;
							break;
						}
					}
					if(found) break;
				}
				if(found) break;
			}
		int tmp = N-a-b-c;
		if(a+b+c>N) return res;
		if(!found) return res;
		if(tmp>0) res.append(tmp,'C');
		res.append(a,'A');
		res.append(b,'B');
		res.append(c,'C');
		}
		return res;
	}
};
