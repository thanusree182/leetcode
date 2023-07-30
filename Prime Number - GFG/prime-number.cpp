//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
        // code here
        int count=0;
        for(int i=1;i*i<=N;i++){
            if(N%i==0){
                count++;
                if((N/i)!=i){
                    count++;
                }
            }
        }
        
        return (count==2);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends