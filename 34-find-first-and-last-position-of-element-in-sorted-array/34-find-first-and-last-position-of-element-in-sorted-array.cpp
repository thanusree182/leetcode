class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> help;
        int a=-1,b=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                a=i;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                b=i;
            }
        }
        return {b,a};
    }
};