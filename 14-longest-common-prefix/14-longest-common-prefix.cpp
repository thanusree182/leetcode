class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n=arr.size();
        string ans;
        sort(arr.begin(),arr.end());
        string a=arr[0];
        string b=arr[n-1];
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])
            ans+=a[i];
            else
            break;
        }
        return ans;
    }
};