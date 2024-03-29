class Solution {
  public:
    int dp[101][101][101];
    
    int func(int prev,int done, int rem, int &n, int &k){
        if(rem==0 && done==k)
            return 1;
        if(rem==0 || done ==k)
            return 0;
            
        if(dp[prev][done][rem] != -1)
            return dp[prev][done][rem];
            
        int ans = 0;
        
        for(int ele = prev;ele<=rem;ele++){
            ans += func(ele,done+1,rem-ele,n,k);
        }
        
        return dp[prev][done][rem] = ans;
    }
  
    int countWaystoDivide(int N, int K) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int ans = func(1,0,N,N,K);
        return ans;
        
    }
};
