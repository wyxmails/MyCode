/*
 You have a stack of n boxes, with widths wi, heights hi, and depths di, Theboxes cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly larger than the box above it in width, height, and depth. Implement a method to build the tallest stack possible, where the height of a stack is the sum of the heights of each box.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box{
	int w,h,d;
	Box(){}
	Box(int w,int h,int d):w(w),h(h),d(d){}
};

bool cmp(const Box&b1,const Box&b2){
	return ((b1.w+b1.h+b1.d)>(b2.w+b2.h+b2.d));
}

void printStack(int index,vector<int>&pre,vector<Box>&boxes){
	while(index!=-1){
		cout << boxes[index].w << "	" << boxes[index].h << "	" << boxes[index].d << endl;
		index = pre[index];
	}
	return ;
}

int GetHeight(vector<Box>& boxes){
	int n = boxes.size();
	if(n==0) return 0;
	if(n==1) return boxes[0].h;
	sort(boxes.begin(),boxes.end(),cmp);
	vector<int> mark(n,0);
	vector<int> pre(n,-1);
	for(int i=0;i<n;++i){
		cout << "(" << boxes[i].w << " " << boxes[i].h << " " << boxes[i].d << ")";
		mark[i] = boxes[i].h;
		for(int j=0;j<i;++j){
			if(boxes[i].w<boxes[j].w&&boxes[i].h<boxes[j].h&&boxes[i].d<boxes[j].d){
				if(mark[j]+boxes[i].h>mark[i]){
					mark[i] = mark[j]+boxes[i].h;
					pre[i] = j;
				}
				//mark[i] = max(mark[i],mark[j]+boxes[i].h);

			}
		}
	}
	cout << endl;
	int index=0;
	int Max = mark[0];
	for(int i=1;i<n;++i){
		if(mark[i]>Max){
			index = i;
			Max = mark[i];
		}
		//Max = max(Max,mark[i]);
	}
	cout << "stack: " << endl;
	printStack(index,pre,boxes);
	return Max;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%10;
	vector<Box> boxes;
	for(int i=0;i<n;++i){
		int w = rand()%20+1, h = rand()%20+1, d = rand()%20+1;
		Box b(w,h,d);
		boxes.push_back(b);
		cout << "(" << w << " " << h << " " << d << ")";
	}
	cout << endl;
	cout << "result: " <<  GetHeight(boxes) << endl;
	return 0;
}
