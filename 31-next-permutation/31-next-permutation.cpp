class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k,l;
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1]){ //to check breakpoint
                break;
            }
        }
        if(k<0){
            reverse(nums.begin(),nums.end()); //if no breakpoint exists we just reverse it
        }
        else{  //else we do our method
            for(l=n-1;l>k;l--){
                if(nums[l]>nums[k]){
                    break;   //to find value of l
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
        
    }
};