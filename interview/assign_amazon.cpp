/*
 *Given an unsorted array, 
 assign every element to its immediate larger number
 after the current number, assign to -1 if no such number exists
 Eg. 3 1 2 5 9 4 8 should be converted to
 5 2 5 9 -1 8 -1
 * */
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
using namespace std;

vector<int> assign(vector<int> vec){
    int n = vec.size();
    stack<int> ms;
    vector<int> res(n,-1);
    for(int i=0;i<n;++i){
        while(!ms.empty()&&vec[i]>vec[ms.top()]){
            res[ms.top()] = vec[i];
            ms.pop();
        }
        ms.push(i);
    }
    return res;
}

int main(int argc,char*argv[]){
    ifstream ifs("assign_amazon.in");
    ofstream ofs("assign_amazon.out");
    string line;
    while(getline(ifs,line)){
        stringstream ss(line);
        vector<int> vec;
        int tmp;
        while(ss>>tmp){ss.ignore(); vec.push_back(tmp);}
        vector<int> res = assign(vec);
        for(int i=0;i<res.size();++i)
            ofs << res[i] <<  " ";
        ofs << endl;
    }
    return 0;
}
