#include <iostream>
using namespace std;

enum suit{
    A=0,B,C,D
};

ostream& operator<<(ostream&out,const suit value){
    string s;
    #define PROC_VAL(p) case(p): s= #p;break;
    switch(value){
        PROC_VAL(A);
        PROC_VAL(B);
        PROC_VAL(C);
        PROC_VAL(D);
    }
    return out << s;
}

int main(int argc,char*argv[]){
    suit s=suit(0);
    cout << s << endl;
    s = suit(3);
    cout << s << endl;
    return 0;
}
