//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(string s,int l,int r,set<string>& st){
	        if(l==r){
	            st.insert(s);
	        }
	        else{
	            for(int i=l;i<=r;i++){
	                swap(s[l],s[i]);
	                solve(s,l+1,r,st);
	                swap(s[l],s[i]);
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int l=0;
		    set<string> st;
		    int h=S.length()-1;
		   solve(S,l,h,st);
		   vector<string> ans(st.begin(),st.end());
		   return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends