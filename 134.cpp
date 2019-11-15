class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            gas[i] -= gas[i] - cost[i];
            sum += gas[i];
        }
        if(sum < 0) return -1;
        
        int i=0; 
        int begin=0;
        int tank=0;
        while(1){
            int j = i%n;
            tank += gas[j];
            if(tank < 0){
                tank = 0;
                begin= (i+1)%n; // 从下一个开始
            }
            if(i>10000) return begin;
            i++; 
        }
    }
};