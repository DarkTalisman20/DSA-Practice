#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin>>n;
    vector<ll> a(n); 
    for(ll i= 0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll currlimit = 0;
    for(ll i = 0;i<n;i++){
        if(a[i]-currlimit>1){
            cout<<currlimit+1<<endl;
            return 0;
        }
        else{
            currlimit = currlimit+a[i];
        }
    }
    cout<<currlimit+1<<endl;
    return 0;
}