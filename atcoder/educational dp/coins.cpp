#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
    int n; cin>>n;
    vector<ld> p(n);
    for(int i = 0;i<n;i++) cin>>p[i];
    vector<vector<ld>> dp(n+1,vector<ld>(n+1,0));
    dp[1][1] = p[0]; dp[1][0] = 1 - p[0];
    for(int i = 2;i<=n;i++){
        for(int j = 0; j<=i; j++){
            if(j==0){
                dp[i][j] = (1-p[i-1])*dp[i-1][j];
            }
            else{
                dp[i][j] = (p[i-1]*dp[i-1][j-1]) + ((1-p[i-1])*dp[i-1][j]);
            }
        }
    }
    ld res = 0;
    for(int i = n;i>= (n/2) + 1; i--){
        res += dp[n][i];
    }
    cout<<fixed<<setprecision(10)<<res<<'\n';
    return 0;
}