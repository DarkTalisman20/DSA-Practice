#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<ll> p;
    ll l = 0;
    ll c = 0;
    for(ll r = 0; r < n; r++){
        if(a[r] == 1){
            c++;
        } 
        if(r-l+1 == k){
            if(c == 0){
                p.push_back(l);
            }
            if(a[l] == 1){
                c--;
            }
            l++;
        }
    }
    if(p.empty()){
        cout<<0<<endl;
        return;
    }
    ll h = 1;
    ll L = p[0];
    for(ll i = 1; i < p.size(); i++){
        if(p[i] > L+k){
            h++;
            L = p[i];
        }
    }
    cout<<h<<endl;
}

int main(){
    ll t = 1; cin >> t;
    while(t--){
        fn();
    }
    return 0;
}
