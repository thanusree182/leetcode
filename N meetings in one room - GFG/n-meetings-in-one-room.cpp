// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    // int maxMeetings(int start[], int end[], int n)
    // {
    //     // Your code here
    //     pair<int,int> p[n+1];
    //     for(int i=0;i<n;i++){
    //         p[i].first=start[i];
    //         p[i].second=i+1;
    //     }
    //     sort(p,p+n);
    //     int limit=p[0].first;
    //     vector<int> ans;
    //     ans.push_back(p[0].second);
    //     for(int i=0;i<n;i++){
    //          if(start[p[i].second]>limit)
    //         {
    //             ans.push_back(p[i].second); 
    //          limit=p[i].first;  
    //         }
            
    //     }
    //       return ans.size()-1;
    // }
    


int maxMeetings(int start[], int end[], int n)
    {
        
        // Your code here
        pair<int,int>pr[n+1];
        
        //copying the ending time of meeting and sort according to its end time
        for(int i=0;i<n;i++)
        {
            pr[i].first=end[i]; //stroing the value 
            pr[i].second=i;     //storing the index
        }
        sort(pr,pr+n);
        
        int time_limit=pr[0].first;
        
        vector<int>ans;
        ans.push_back(pr[0].second + 1); //storing the meeting nu. which happended first
        
        //check for all the remaining meeting in the order
        for(int i=1;i<n;i++)
        {
            //check start time of another jaldi ending meeting greater than endtime of previosus meeting 
            if(start[pr[i].second]>time_limit)
            {
                ans.push_back(pr[i].second + 1); //stroing the meeting number
                time_limit=pr[i].first; //set a new time limit to the meeting that is happended 
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