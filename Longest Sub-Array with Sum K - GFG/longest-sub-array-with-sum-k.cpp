//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int ans=0;
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum==K){
                ans=max(ans,i+1);
            }
            if(mp.find(sum-K)!=mp.end()){
                int index=mp[sum-K];
                if(index<=i)ans=max(ans,i-index);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;     //if there are zeros in b/w we take as much left as possible so we dont 
                //update sum to later index as sum will not change if  zeros in b/w
            }
        }
        return ans;
    } 
        

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends