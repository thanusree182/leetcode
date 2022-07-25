class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        vector<int> ans(2,-1);
        while(s<=e){
        int m=s+(e-s)/2;
            if(nums[m]<target){
                s=m+1;
            }
            else if(nums[m]>target){
                e=m-1;
            }
            else {
                if(m == s || nums[m] != nums[m-1]){
				ans[0] = m;
				break;
			}
			else{
				e = m-1;
				ans[0] = m-1;
			}
            }
        }
        
        s=0,e=nums.size()-1;
        
        while(s<=e){
        int m=s+(e-s)/2;
            if(nums[m]<target){
                s=m+1;
            }
            else if(nums[m]>target){
                e=m-1;
            }
            else {
                if(m==e || nums[m]!=nums[m+1] ){
                    ans[1]=m;
                    break;
                }
                else{
                    s=m+1;
                    ans[1]=m+1;
                }
                    
                
            }
        }
        return ans;
    }
};


