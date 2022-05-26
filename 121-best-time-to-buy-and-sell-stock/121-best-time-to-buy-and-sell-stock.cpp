

class Solution {
public:
    int maxProfit(vector<int>& arr) {

        int max_val=0,min_val=INT_MAX;
        for(int i=0;i<arr.size();i++){
            min_val=min(min_val,arr[i]);
            max_val=max(max_val,arr[i]-min_val);
        }
        return max_val;
    }
};

