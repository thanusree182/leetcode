//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        
        // Your code goes here
        vector<int> v1;
        vector<int> v2;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]>=0) v1.push_back(arr[i]);
            else v2.push_back(arr[i]);
        }
        
        int i=0, j = 0;
        int k = 0;
        while(i<v1.size())
        {
            arr[k++] = v1[i++];
        }
        
        while(j<v2.size())
        {
            arr[k++] = v2[j++];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends