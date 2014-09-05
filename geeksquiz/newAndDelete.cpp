#include <iostream>
using namespace std;

//new compare to malloc
/*
 1) new is an operator, malloc is a function 
 2) new calls constructor, malloc doesn't 
 3) new returns appropriate pointer, malloc returns void * and pointer needs to typecast to appropriate type. 
 */

int main(int argc,char*argv[]){
	//a dynamic array of pointers (to integers) of size 10
	int **arr = new int*[10]; 
	//a non-dynamic array
	int *narr[10];
	//Deleting a null pointer has no effect,
	//so it is not necessary to check for a null pointer before calling delete
	int *ptr = NULL;
	delete ptr;
	//delete twice on a pointer will crash or produce nothing
	int *p = new int;
	delete p;
	//delete p;
	cout << "done" << endl;
	return 0;
}
