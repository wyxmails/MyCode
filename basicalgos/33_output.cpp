#include <iostream>
#include <cstdio>
using namespace std;
//if there is not the static variable num,
//This function will print out a list of 5, 
//and then hit stack overflow due to infinite recursion.
void myFunction(int n)
{
	static int num = 0;
	num++;
	if(num==10) return;
	if (n == 0)  return;   
	printf("%d ", n);
	myFunction(n--);
	printf("%d ", n);
}
int main(){
	myFunction(5);
	return 0;
}
