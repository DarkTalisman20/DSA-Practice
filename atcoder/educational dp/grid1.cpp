#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int MOD = 1e9 + 7;

int main(){
    int h, w; cin>>h>>w;
    vector<vector<char>> grid(h,vector<char>(w));
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(h+1,vector<int>(w+1,0));
    dp[1][1] = 1;
    for(int i = 1;i<=h;i++){
        for(int j = 1;j<=w;j++){
            if((i==1 && j==1) || grid[i-1][j-1]=='#')    continue;
            int a = 0;
            if(i>=2){
                a = ((grid[i-2][j-1]=='#')?0 : dp[i-1][j]);
            }
            int b = 0;
            if(j>=2){
                b = ((grid[i-1][j-2]=='#')?0:dp[i][j-1]);
            }
            dp[i][j] = (a+b)%MOD;
        }
    }
    cout<<dp[h][w]<<'\n';
}