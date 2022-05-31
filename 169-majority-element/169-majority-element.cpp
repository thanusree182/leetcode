class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(int a:nums){
            if(count==0){
                candidate=a;
            }
            if(a==candidate){
                count++;
            }
            else
                count--;
        }
        return candidate;
    }
};