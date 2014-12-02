//公式推导：V2=iR=CR d/dt(Vs*cos(wt)-Vr*cos(wt+b))=Vrcos(wt+b)
//          CRw(sin(wt+b)-sin(wt))=Vr*cos(wt+b)
//          令t=0化简得：   tan(b)=1/(CRw)-------------(1)
//          令wt+b=0化简得：Vr=CRwVs*sin(b)------------(2)
//          由(1),(2)得：   Vr=CRwVs/sqrt(1+(CRw)^2))
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main(int argc,char*argv[]){
	double Vs,R,C,w,Vr;
	int n;
	cin>>Vs>>R>>C>>n;
	while(n){
		cin>>w;
		Vr = C*R*w*Vs/sqrt(1+C*R*w*w*R*C);
		cout << fixed << setprecision(3) << Vr << endl;
		n--;
	}
	return 0;
}
