class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> help;
        func(nums,ans,help,0);
        return ans;
    }
    void func(vector<int> &nums,vector<vector<int>>&ans, vector<int> &help,int i){
        if(i==nums.size()){
          ans.push_back(help);
            return;
        }
        help.push_back(nums[i]);
        func(nums,ans,help,i+1);
        help.pop_back();
        func(nums,ans,help,i+1);
    }
};