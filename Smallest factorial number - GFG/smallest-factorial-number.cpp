//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
        int num=1;
        int count=0;
        while(true){
            int temp=num;
            while(temp%5==0){
                count++;
                temp/=5;
            }
            if(count>=n){
                return num;
            }
            num++;
        }
        return num;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends