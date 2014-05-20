#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int buffer[4096];
	long sum = 0;
	ifstream file("binary.dat",ios::in|ios::binary);
	if(file.is_open()){
		while(!file.eof()){
			file.read(reinterpret_cast < char* >(buffer), sizeof(buffer));
			int num_bytes = file.gcount();
			for(int i=0;i<num_bytes/sizeof(unsigned int);++i){
				sum += buffer[i];
				cout << buffer[i] << endl;
			}
		}
	}
	file.close();
}
