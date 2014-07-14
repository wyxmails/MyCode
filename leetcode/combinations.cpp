/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
void myCom(set<vector<int> >& res,vector<int>& cur,int l,int r,int k){
        if(cur.size()==k){
            res.insert(cur);
            return;
        }
        for(int i=l;i<=r-(k-cur.size())+1;++i){
            cur.push_back(i);
            myCom(res,cur,i+1,r,k);
            cur.pop_back();
        }
}
    
vector<vector<int> > combine(int n, int k) {
        set<vector<int> > res;
        vector<int> cur;
        for(int i=1;i<=n-k+1;++i){
            cur.push_back(i);
            myCom(res,cur,i+1,n,k);
            cur.pop_back();
        }
        vector<vector<int> > final;
        set<vector<int> >::iterator it = res.begin();
        while(it!=res.end()){
            final.push_back(*it);
            it++;
        }
        return final;
}
