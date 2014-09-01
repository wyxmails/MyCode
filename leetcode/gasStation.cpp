class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n=gas.size();
        if(n==0) return 0;
        int tank;
        bool suc;
        for(int i=0;i<n;){
            tank = 0;
            suc = true;
            int j=i;
            for(;j-i<n&&suc;++j){
                int tmp = j%n;
                if(gas[tmp]+tank<cost[tmp]){
                    suc = false;
                }else
                    tank = tank+gas[tmp]-cost[tmp];
            }
            if(suc) return i;
            i = j;
        }
        return -1;
    }
};
