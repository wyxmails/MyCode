/*
 Given an image represented by an NxN matrix, 
 where each pixel in the image is 4 bytes, 
 write a method to rotate the image by 90 degrees. 
 Canyou do this in place?
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int> > &image){
	int n = image.size();
	if(n<=1) return ;
	for(int i=0;i<n;++i){
		for(int j=0;j<n/2;++j){
			int tmp = image[i][j];
			image[i][j] = image[i][n-j-1];
			image[i][n-j-1] = tmp;
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n-i;++j){
			int tmp = image[i][j];
			image[i][j] = image[n-j-1][n-i-1];
			image[n-j-1][n-i-1] = tmp;
		}
	}
}

int main(int argc,char*argv[]){
	int n = 5;
	vector<vector<int> > image(n,vector<int>(n,0));
	srand(time(NULL));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			int tmp = rand()%50;
			image[i][j] = tmp;
			cout << tmp << " ";
		}
		cout << endl;
	}
	rotate(image);
	cout << "after roate" << endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout << image[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
