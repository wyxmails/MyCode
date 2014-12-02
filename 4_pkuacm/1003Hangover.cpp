#include <iostream>
using namespace std;
int main()
{
	double a;
	while(cin >> a){
		double b=a;
		int i=0;
		while(b>0.001){
			++i;
			b = b - (float)1/(i+1);
		}
		if(a>0.00)
			cout << i << " card(s)" << endl;
	}
	return 0;
}
