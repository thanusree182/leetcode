class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int n=nums.size();
        int a=1,b=1;
        for(int i=0;i<n;i++){
            a*=nums[i];
            b*=nums[n-i-1];
            res=max(res,max(a,b));
            if(a==0)
                a=1;
            if(b==0)
                b=1;
        }
        return res;
    }
};