#include <iostream>
using namespace std;

/*
 1) Template is a feature of C++ that allows us to write one code for different data types.

 2) We can write one function that can be used for all data types including user defined types. Like sort(), max(), min(), ..etc.

 3) We can write one class or struct that can be used for all data types including user defined types. Like Linked List, Stack, Queue ..etc.

 4) Template is an example of compile time polymorphism.
 */

template <typename T>
void fun(const T&x){
	static int count = 0;
	cout << "x= " << x << " count= " << count << endl;
	++count;
	return;
}
template <typename T>
T Max(T x,T y){
	return (x>y)?x:y;
}
template <class T>
class Test{
	private:
		T val;
	public:
		static int count;
		Test(){count++;}
};
template<class T>
int Test<T>::count = 0;

template<class T,class U>
class A{
	T x;
	U y;
	static int count;
};


template<class T,class U,class V=double>
class B{
	T x;
	U y;
	V z;
	static int count;
};

template <class T,int Max>
int arrMin(T arr[], int n){
	int m = Max;
	for(int i=0;i<n;++i)
		if(arr[i]<m)
			m = arr[i];
	return m;
}

template <int i>
void fun(){
	//i=20; //compiler error
	//int i=i; //shadow error
	int j=i;
	static int count=0;
	cout << "count: " << count << endl;
	count++;
	cout << j << endl;
}
//template specialization
template <class T>
T MM(T&a,T&b){
	return (a>b)?a:b;
}
template <>
int MM <int>(int&a,int&b){
	cout << "Called " ;
	return (a>b)?a:b;
}

//template metaprogramming
template<int n> struct funStruct{
	static const int val = 2*funStruct<n-1>::val;
};
template<>struct funStruct<0>{
	static const int val = 1;
};
int main(int argc,char*argv[]){
	fun<int>(1);
	fun<int>(1);
	fun<double>(1);
	cout << Max(3, 7) << endl;
	cout << max(3.0, 7.0) << endl;
	//cout << max(3,7.0) << endl; //compiler error, ambiguous
	Test<int> a;
	Test<int> b;
	Test<double> c;
	cout << Test<int>::count << endl;
	cout << Test<double>::count << endl;
	A<char,char> obja;
	A<int,int> objb;
	cout << sizeof(obja) << endl;
	cout << sizeof(objb) << endl;
	B<int,int> bb;
	B<double,double> bc;
	cout << sizeof(bb) << endl;
	cout << sizeof(bc) << endl;
	int arr1[] = {10,20,15,12};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout << "n1: " << n1 << endl;
	char arr2[] = {1,2,3};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	cout << "n2: " << n2 << endl;
	int *arr3 = arr1;
	cout << "n3: " << sizeof(arr3)/sizeof(arr3[0]) << endl;
	cout << arrMin<int,10000>(arr1,n1) << endl;
	cout << arrMin<char,256>(arr2,n2) << endl;
	//
	fun<10>();
	fun<10>();
	fun<20>();
	//template specialization
	int aaa=10,bbb=20;
	cout << MM<int>(aaa,bbb) << endl;
	//template metaprogramming
	cout << funStruct<10>::val << endl; //calculation is done at compile time
	return 0;
}
