#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)  cin>>v[i];
    ll cnt = 0;
    ll maxele = v[n-1];
    for(ll i = 0;i<n;i++){
        for(ll j = i+1;j<n;j++){
            if(j==n-1){
                continue;
            }
            ll l = j+1; ll r = n-1;
            ll idx = -1;
            while(l<=r){
                ll m = l + (r-l)/2;
                if(v[m]<(v[i]+v[j])){
                    idx = m;
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
            if(idx!=-1){
                ll idx2 = -1;
                ll lt = j+1, rt = idx;
                while(lt<=rt){
                    ll mt = lt + (rt-lt)/2;
                    if(v[i]+v[j]+v[mt] > maxele){
                        rt = mt-1;
                        idx2 = mt;
                    }
                    else{
                        lt = mt+1;
                    }
                }
                if(idx2!=-1){
                    cnt+=(idx-idx2+1);
                }
            }
        }
    }
    cout<<cnt<<endl;
}

int main(){
    ll t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}