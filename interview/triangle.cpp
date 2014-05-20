#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc,char*argv[]){
	int lines=100;
	int array[lines][lines];
	for(int i=0;i<lines;++i){
		for(int j=0;j<=i;++j){
			scanf("%d",&array[i][j]);
		}
	}
	for(int i=lines-2;i>=0;--i){
		for(int j=0;j<=i;++j){
			array[i][j] = max(array[i+1][j],array[i+1][j+1]) + array[i][j];	
		}
	}
	printf("%d\n",array[0][0]);
	return 0;
}
