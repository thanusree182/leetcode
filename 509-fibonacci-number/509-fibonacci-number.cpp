class Solution {
public:
    int f[31]={0};
    int fib(int n) {
        if(n<=1){
            return n;
        }
        if(f[n]){
            return f[n];
        }
        return f[n]=fib(n-1)+fib(n-2);
    }
};