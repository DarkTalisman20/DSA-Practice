#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
    ld n; cin>>n;
    vector<ld> cnt(4);
    for(ld i = 0;i<n;i++){
        ld x; cin>>x; cnt[x]++;
    }
    vector<vector<vector<ld>>> dp(n+1,vector<vector<ld>>(n+1,vector<ld>(n+1,0)));
    
    for(int k=0;k<=n;k++){
        for(int j=0;j<=n;j++){
            for(int i=0;i<=n;i++){
                if(i==0 && j==0 && k==0)    continue;
                if(i + j + k > n)   continue;
                dp[i][j][k]++;
                if(i>0){
                    dp[i][j][k] += (i/n)*dp[i-1][j][k];
                }
                if(j>0){
                    dp[i][j][k] += (j/n)*dp[i+1][j-1][k];
                }
                if(k>0){
                    dp[i][j][k] += (k/n)*dp[i][j+1][k-1];
                }
                dp[i][j][k] *= (n/(i+j+k));  
            }
        }
    }
    cout<<fixed<<setprecision(10)<<dp[cnt[1]][cnt[2]][cnt[3]]<<'\n';
    return 0;
}