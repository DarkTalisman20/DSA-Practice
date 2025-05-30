#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    vector<int> dp(k+1,0);
    for(int i = 0;i<=k;i++){
        if(i<a[0])  continue;
        for(int j = n-1;j>=0;j--){
            if(a[j]>i)  continue;
            else{
                if(dp[i-a[j]] == 0){
                    dp[i] = 1; break;
                }
            }
        }
    }
    if(dp[k]==1) cout<<"First"<<'\n';
    else cout<<"Second"<<'\n';
    return 0;
}