class Solution {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums)+1,-1);
        return solve(nums,0,-1);
    }
    int solve(vector<int>& nums,int ind,int prev){
        if(ind>=nums.size())
            return 0;
        if(dp[prev+1]!=-1){
            return dp[prev+1];
        }
        int dont_take=solve(nums,ind+1,prev);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            take=1+solve(nums,ind+1,ind);
        }
        return dp[prev+1]=max(take,dont_take);
    }
    
    
};

