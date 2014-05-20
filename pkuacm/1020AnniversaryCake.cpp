#include <iostream>
using namespace std;

int square[40];
int sides[11];
int cakesize;

int dfs(int numpiece){
	if(0==numpiece){
		return 1;
	}
	int width,height,minheight,left,right;
	minheight = cakesize;
	left = right = -1;
	for(int i=0;i<cakesize;++i){
		if(square[i]<minheight){
			minheight = square[i];
			left = i;
		}
		if(square[i]>minheight&&left>right){
			right = i;
		}
	}
	if(right>left) width = right - left;
	else width = cakesize - left;
	height = cakesize - minheight;
	for(int i=width<height?width:height;i>0;--i){
		if(sides[i]>0){
			sides[i]--;
			for(int j=0;j<i;++j) square[j+left] += i;
			if(dfs(numpiece-1)) return 1;
			for(int j=0;j<i;++j) square[j+left] -= i;
			sides[i]++;
		}
	}
	return 0;
}

int main(int argc,char*argv[]){
	int testcase, piece,  numpiece, sum;
	cin >> testcase;
	for(int i=0;i<testcase;++i){
		sum = 0;
		for(int j=0;j<40;++j){
			square[j] = 0;
		}
		for(int j=0;j<11;++j){
			sides[j] = 0;
		}
		cin >> cakesize;
		cin >> numpiece;
		for(int j=0;j<numpiece;++j){
			cin >> piece;
			sum += piece*piece;
			sides[piece]++;
		}
		if(sum!=(cakesize*cakesize)){
			cout << "HUTUTU!" << endl;
		}else{
			if(dfs(numpiece)){
				cout << "KHOOOOB!" << endl;
			}else{
				cout << "HUTUTU!" << endl;
			}
		}
	}
	return 0;
}
