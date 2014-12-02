/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> myStack;
        int n = path.size();
        int s = 0;
        while(path[s]=='/') s++;
        int e = s;
        s--;
        while(e<n){
            while(e<n&&path[e]!='/') e++;
            string cur = path.substr(s,e-s);
            s = e;
            while(s<n&&path[s]=='/') s++;
            e = s;
            s--;
            if(cur=="/.."){
                if(!myStack.empty())
                    myStack.pop();
            }else if(cur!="/.") myStack.push(cur);
        }
        string res = "";
        while(!myStack.empty()){
            res = myStack.top()+res;
            myStack.pop();
        }
        if(res=="") res = '/';
        return res;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ms;
        int start=0,n=path.size();
        for(int i=0;i<=n;++i){
            if(i==n||path[i]=='/'){
                string tmp = path.substr(start,i-start);
                start = i+1;
                if(tmp==".."){
                    if(!ms.empty()) ms.pop();
                }else if(tmp!="."&&tmp.size()>0)
                        ms.push(tmp);
            }
        }
        if(ms.empty()) return "/";
        string res = "";
        while(!ms.empty()){
            res = "/"+ms.top()+res;
            ms.pop();
        }
        return res;
    }
};
