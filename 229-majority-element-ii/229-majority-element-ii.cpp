class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n=nums.size();
        unordered_map<int,int> help;
        vector<int> ans;
        for(int i=0;i<n;i++){
               help[nums[i]]++;
        }
        for(auto i:help){
               if(i.second>n/3){
                   ans.push_back(i.first);
               }
        }
        
       return ans;
    }
};