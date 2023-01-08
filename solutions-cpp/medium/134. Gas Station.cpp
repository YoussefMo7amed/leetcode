class Solution {
   public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        long long c_gas = 0; // cumulative_gas
        long long c_cost = 0; // cumulative_cost
        long long diff = 0;
        int index = 0;

        for (int i = 0; i < gas.size(); i++) {
            c_gas += gas[i];
            c_cost += cost[i];
            diff += (gas[i] - cost[i]);

            if(diff < 0){
                diff = 0;
                index = i + 1;
            }
        }
        return c_gas - c_cost < 0 ? -1 : index;
    }
};