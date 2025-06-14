#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++) cin>>v[i];
    ll r = 0, sum = 0,maxsum=v[0];
    while(r<n){
        sum+=v[r];
        maxsum=max(maxsum,sum);
        if(sum<0){
            sum=0;
            r++;
        }
        else{
            r++;
        }
    }
    cout<<maxsum<<endl;
    return 0;
}