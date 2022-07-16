class Solution {
    public:
     int dp[51][51][52];
     int mod=1e9+7;
    
    int check(int m,int n, int moves,int r,int c){
       
       
       
        int ans=0;
        if(r<0 || r>=m || c<0 || c>=n){
            return 1;
        }
        if(moves==0){
            return 0;
        }
        if(dp[r][c][moves]!=-1){
            return dp[r][c][moves];
        }
        ans = ( ans + check(m,n,moves-1,r-1,c)) % mod; 
        ans = ( ans + check(m,n,moves-1,r+1,c)) % mod; 
        ans = ( ans +check(m,n,moves-1,r,c+1)) % mod; 
        ans = ( ans + check(m,n,moves-1,r,c-1)) % mod;    
        return dp[r][c][moves]=ans;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
         memset(dp,-1,sizeof(dp));
       return check(m,n,maxMove,startRow,startColumn);
    }
};

