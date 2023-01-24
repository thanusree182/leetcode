//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int min_length=n+1;
        int curr_sum=0;
        int start=0,end=0;
        while(end<n){
            while(curr_sum<=x && end<n){
                curr_sum+=arr[end++];
            }
            while(curr_sum>x && start<n){
                if(end-start<min_length){
                    min_length=end-start;
                }
                curr_sum-=arr[start++];
            }
        }
        return min_length;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends