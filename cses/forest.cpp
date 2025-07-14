#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,q; cin>>n>>q;
    vector<vector<char>> grid(n,vector<char>(n));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>> d(n,vector<ll>(n,0));
    d[0][0] = (grid[0][0]=='*')?1:0;
    for(ll i = 1;i<n;i++){
        d[i][0] = d[i-1][0] + ((grid[i][0]=='*')?1:0);
        d[0][i] = d[0][i-1] + ((grid[0][i]=='*')?1:0);
    }
    for(ll i = 1;i<n;i++){
        for(ll j = 1;j<n;j++){
            d[i][j] = ((grid[i][j]=='*')?1:0) + d[i][j-1] + d[i-1][j] - d[i-1][j-1];
        }
    }
    for(ll i = 0;i<q;i++){
        ll y1, x1, y2, x2;
        cin>>x1>>y1>>x2>>y2; --y1; --x1; --y2; --x2;
        cout<<d[x2][y2] + ((x1>0 && y1>0)?d[x1-1][y1-1]:0) - ((y1>0)?d[x2][y1-1]:0) - ((x1>0)?d[x1-1][y2]:0)<<endl; 
    }
    return 0;
}