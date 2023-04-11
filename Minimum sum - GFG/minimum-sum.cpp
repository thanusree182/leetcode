//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // string string_sum(string s1,string s2){
        
    // }
     string string_sum(string X,string Y){
         
        if (X.length() >Y.length())
        swap(X, Y);
        int n=X.length(),m=Y.length();
        int diff=m-n;
        string str;
        int carry=0;
        for(int i=n-1;i>=0;i--){
            int sum=(X[i]-'0')+(Y[i+diff]-'0')+carry;
            str.push_back(sum%10+'0');
            carry=sum/10;
        }
        for(int i=m-n-1;i>=0;i--){
            int sum=(Y[i]-'0')+carry;
            str.push_back(sum%10+'0');
            carry=sum/10;
        }
         if (carry)
        str.push_back(carry+'0');
        
         
         int k = str.size()-1;//for removing all zeros which comes at front
        while(k>=1 && str[k]=='0' ){
            str.pop_back();
            k--; 
        }
         reverse(str.begin(),str.end());
          return str;
    }
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string s1,s2;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(arr[i]==0 && s1.length()==0){
                    continue;
                }
                s1+=to_string(arr[i]);
            }
            else{
                if(arr[i]==0 && s2.length()==0){
                    continue;
                }
                s2+=to_string(arr[i]);
            }
        }
        return string_sum(s1,s2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends