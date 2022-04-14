class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n+1,0);
        for(int i=0;i<nums.size();i++){
            if (a[nums[i]]!=0)
                return nums[i];
        
        else
        {
            a[nums[i]]++;
        }
        }
        return 0;
    }
};