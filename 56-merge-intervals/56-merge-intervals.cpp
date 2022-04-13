
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0)
            return intervals;
        
        sort(intervals.begin(),intervals.end());
        vector<int> help=intervals[0];
        for(auto it: intervals){
            if(it[0]<=help[1]){  //1st pair gets automatically merged as we took same in help at start and then we update help the max value
                help[1]=max(it[1],help[1]);
            }
            else
            {
                ans.push_back(help); //if they are not merging we add it to our ans array as it is unique
                help = it; //updating help 
            }
        }
        ans.push_back(help);
        return ans;
    }
};