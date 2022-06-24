// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int,int> p[n+1];
        for(int i=0;i<n;i++){
            p[i].first=end[i];
        p[i].second=i;
        }
        sort(p,p+n);
        int limit=p[0].first;
        vector<int> ans;
        ans.push_back(p[0].second+1);
        for(int i=1;i<n;i++){
            if(start[p[i].second]>limit){
                ans.push_back(p[i].second+1);
                limit=p[i].first;
            }
        }
        
        return ans.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends