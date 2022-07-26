class Solution {
public:
    void helper(vector<string> &s,int n, int oc,int cc, string a){
        if(oc==n && cc==n ){
            s.push_back(a);
            return;
        }
        if(oc<n){
            helper(s,n,oc+1,cc,a+'(');
        }
        if(cc<oc){
            helper(s,n,oc,cc+1,a+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        int oc=0,cc=0;
        helper(s,n,oc,cc,"");
        return s;
    }
};