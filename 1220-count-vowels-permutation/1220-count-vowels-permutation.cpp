class Solution {
public:
    int countVowelPermutation(int n) {
        long a=1,e=1,i=1,o=1,u=1,mod=pow(10,9)+7;
        long a1=1,e1=1,i1=1,o1=1,u1=1;
        for(int j=2;j<=n;j++){
            a1=(e+i+u)%mod;
            e1=(a+i)%mod;
            i1=(e+o)%mod;
            o1=i;
            u1=(i+o)%mod;
            a=a1,e=e1,i=i1,o=o1,u=u1;
        }
        return (a+e+i+o+u)%mod;
    }
};