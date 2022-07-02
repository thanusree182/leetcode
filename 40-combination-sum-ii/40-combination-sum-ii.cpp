class Solution {
    public:
    void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int index){
        if(target==0){
            res.push_back(r);
            return;
        }
       for(int i=index;i<candidates.size();i++){
           if(candidates[i]>target)
               break;
           if(i>index && candidates[i-1]==candidates[i]){
               continue;
           }
           r.push_back(candidates[i]);
           Sum(candidates,target-candidates[i],res,r,i+1);
           r.pop_back();
       }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
 sort(candidates.begin(),candidates.end());
             
        vector<int> r;
        vector<vector<int>> res;
        Sum(candidates,target,res,r,0);
        return res;
    }
    
};
