#include <iostream>
using namespace std;

typedef struct color{
	int R;
	int G;
	int B;
}color;

int main(int argc,char*argv[]){
	int r,g,b,rout,gout,bout;
	int min,tmp;
	color tset[16];
	for(int i=0;i<16;++i){
		cin>>tset[i].R>>tset[i].G>>tset[i].B;
	}
	int max = 255*255*3+1;
	while(cin>>r>>g>>b&&(!(r==-1&&g==-1&&b==-1))){
		min = max;
		for(int i=0;i<16;++i){
			tmp = (tset[i].R-r)*(tset[i].R-r)
				+(tset[i].G-g)*(tset[i].G-g)
				+(tset[i].B-b)*(tset[i].B-b);
			if(tmp==0){
				rout = tset[i].R;
				gout = tset[i].G;
				bout = tset[i].B;
				break;
			}
			if(min>tmp){
				rout = tset[i].R;
				gout = tset[i].G;
				bout = tset[i].B;
				min = tmp;
			}
		}
		cout << "(" << r << "," << g << "," << b << ") maps to ("
			<< rout << "," << gout << "," << bout << ")" << endl;
	}
	return 0;
}
