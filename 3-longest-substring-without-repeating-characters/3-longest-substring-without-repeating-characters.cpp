class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        int l=0,r=0,len=0;
        int n=s.size();
        while(r<n){
            if(mpp[s[r]]!=-1)
                l=max(mpp[s[r]]+1,l);
                mpp[s[r]]=r;
                len=max(len,r-l+1);
                r++;
        }
        return len;
    }
};

