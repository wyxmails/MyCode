/*思路：
* (1)微分公式转化，
*   di=I0*|cosα|*dl*h=k/r*|cosα|*dl*h=k/r*cosα*(r*dα/sin(90-α))*h=kh*dα；
*   转化细节画个图一目了然。所以问题就转化为求原点对该几何图形的张角。
*
* (2)张角的求法：求出原点对首尾相接的每条线段的张角θ（-PI<=θ<=PI)，
*   进行累加，记录每一步累加的最大值max和最小值min，max-min就是张角，
*   由于题目要求，张角小于等于2*PI。
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef struct point{
	double x;
	double y;
}point;

int main(int argc,char*argv[]){
	const double pi = acos(-1.0);
	double k,h,minres,maxres,result;
	int N;
	point arrpoint[101];
	scanf("%lf%lf%d",&k,&h,&N);
	scanf("%lf%lf",&arrpoint[0].x,&arrpoint[0].y);
	arrpoint[N] = arrpoint[0];
	minres=maxres=result=0.0;
	for(int i=1;i<=N;++i){
		if(i<N) scanf("%lf%lf",&arrpoint[i].x,&arrpoint[i].y);
		result += fmod((atan2(arrpoint[i].y,arrpoint[i].x)-atan2(arrpoint[i-1].y,arrpoint[i-1].x)+5*pi),2*pi)-pi;
		minres = min(result,minres);
		maxres = max(result,maxres);
	}
	result = min(2*pi,maxres-minres)*k*h;
	printf("%.2f\n",result);
}
