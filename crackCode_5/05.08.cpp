/*
 A monochrome screen is stored as a single array of bytes, 
 allowing eight consecutive pixels to be stored in one byte. 
 The screen has width w, where w is divisible by 8 
 (that is, no byte will be split across rows). 
 The height of the screen, of course, 
 can be derived from the length of the array and the width. 
 Implement a function 
 drawHorizontalLine(byte[] screen,int width, int x1, int x2, int y) 
 which drawsahorizontal line from (x1,y) to (x2, y).
 */

#include <iostream>
#include <vector>
using namespace std;

void drawHorizontalLine(vector<char>& screen, int width, int x1, int x2, int y){
	int start_byte = x1/8;
	int start_bits = x1%8;
	if(start_bits!=0) start_byte++;
	int end_byte = x2/8;
	int end_bits = x2%8;
	if(end_bits!=7) end_byte--;
	for(int i=y*width/8+start_byte;i<=y*width/8+end_byte;++i)
		screen[i] = char(255);
	int left_part = (1<<8-start_bits+1)-1;
	screen[y*width/8+start_byte-1] |= left_part;
	//int right_part = ((1<<end_bits+1)-1)-((1<<8-end_bits-1)-1);
	int right_part = ((1<<end_bits+1)-1)<<(8-end_bits-1);
	screen[y*width/8+end_byte+1] |= right_part;
}	

int main(int argc,char*argv[]){
	char screen[] = {'a','a','a','a','a','a'};
	vector<char> vec;
	for(int i=0;i<sizeof(screen)/sizeof(screen[0]);++i)
		vec.push_back(screen[i]);
	for(int i=0;i<vec.size();++i){
		int tmp = vec[i];
		string bi = "00000000";
		int pos = 0;
		while(tmp>0){
			if(tmp%2) bi[7-pos] = '1';
			else bi[7-pos] = '0';
			pos++;
			tmp /= 2;
		}
		cout << bi << "-";
	}
	drawHorizontalLine(vec,16,3,13,1);
	int tmp = 'a';
	string bi="";
	cout << endl;
	while(tmp>0){
		if(tmp%2) bi = "1"+bi;
		else bi = "0"+bi;
		tmp /= 2;
	}
	cout << bi << endl;
	for(int i=0;i<vec.size();++i){
		tmp = vec[i];
		bi = "00000000";
		int pos = 0;
		while(tmp!=0&&pos<8){
			if(tmp&1) bi[7-pos] = '1';
			else bi[7-pos] = '0';
			pos++;
			tmp >>=1;
		}
		cout << bi << "-";
	}
	cout << endl;
	return 0;
}
