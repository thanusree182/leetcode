// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(size(nums)==0) return 0;
//         if(size(nums)==1) return 1;
//         sort(nums.begin(),nums.end());
//             int n=nums.size();
//         int clong=1,longe=0;
//         for(int i=0;i<n;i++){

 class Solution {
 public:
int longestConsecutive(vector<int>& nums) {
	if(!size(nums)) return 0;
	sort(begin(nums), end(nums));
	int longest = 0, cur_longest = 1;
	for(int i = 1; i < size(nums); i++) 
		if(nums[i] == nums[i - 1]) continue;
		else if(nums[i] == nums[i - 1] + 1) cur_longest++; // consecutive element - update current streak length
		else longest = max(longest, cur_longest), cur_longest = 1;  // reset current streak length
	return max(longest, cur_longest);
}
 };