#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    ll n;
    ll k;
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    ll r;
    for(ll i = 0; i < n; i++){
        cin >> v[i].first >> r >> v[i].second;
    }
    sort(v.begin(), v.end());
    ll c = k;
    ll j = 0;
    priority_queue<ll> q;
    while(true){
        while(j < n && v[j].first <= c){
            q.push(v[j].second);
            j++;
        }
        if(q.empty() || q.top() <= c){
            break;
        }
        c = q.top();
        q.pop();
    }
    cout<<c<<endl;
}

int main(){
    ll t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
