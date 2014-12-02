#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(int argc,char*argv[]){
	char ss[20];
	int lastt=0,speed=0,curt=0;
	double distance=0.0;
	while(gets(ss)){
		if(ss[8]==' '){
			curt = ((ss[0]-'0')*10+(ss[1]-'0'))*3600 
				+ ((ss[3]-'0')*10+(ss[4]-'0'))*60
				+ ((ss[6]-'0')*10+(ss[7]-'0'));
			if(curt<lastt) lastt -= 3600*24;
			distance += (double)speed*(curt-lastt)/3600;
			speed=0;
			int i=9;
			while(ss[i]!='\0'){
				speed = speed*10 + ss[i]-'0';
				i++;
			}
			lastt = curt;
		}else{
			curt = ((ss[0]-'0')*10+(ss[1]-'0'))*3600 
				+ ((ss[3]-'0')*10+(ss[4]-'0'))*60
				+ ((ss[6]-'0')*10+(ss[7]-'0'));
			if(curt<lastt) lastt -= 3600*24;
			distance += (double)speed*(curt-lastt)/3600;
			printf("%c%c:%c%c:%c%c %.2f km\n",
					ss[0],ss[1],ss[3],ss[4],ss[6],ss[7],distance);
			lastt = curt;
		}
	}
	return 0;
}
