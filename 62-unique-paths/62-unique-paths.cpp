class Solution {
public:
    int uniquePaths(int m, int n) {
      int total=n+m-2;
        int r=m-1;
     double res=1;
        for(int i=1;i<=r;i++){
            res=res*(total-r+i)/i;
        }
        return (int)res;
    }
};