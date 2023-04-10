//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        //first we caluculate no.of elements less than k
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                count++;
            }
        }
        //caluculate no.of no.s to be swapped in first window
        int swaps=0;
        for(int i=0;i<count;i++){
            if(arr[i]>k){
                swaps++;
            }
        }
        //now we move the window and check min_swaps window
        int ans=swaps; //these are from 1st window
        for(int i=0,j=count;j<n;++i,++j){
            if(arr[i]>k){
                --swaps;
            }
            if(arr[j]>k){
                ++swaps;
            }
            ans=min(ans,swaps);
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends