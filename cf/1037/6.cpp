#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn() {
    ll n, q; cin>>n>>q;
    vector<ll> c(n + 1);
    for(ll i = 1; i <= n; i++){
        cin>>c[i];
    }
    vector<vector<pair<ll, ll>>> a(n + 1);
    vector<ll> d(n + 1, 0);
    vector<tuple<ll, ll, ll>> e;
    for(ll i = 0; i < n - 1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        d[u]++; d[v]++;
        e.emplace_back(u, v, w);
    }
    ll b = static_cast<ll>(sqrt(n));
    if (b == 0) b = 1;
    vector<bool> h(n + 1, false);
    vector<ll> t;
    for(ll i = 1; i <= n; i++){
        if(d[i] > b){
            h[i] = true;
            t.push_back(i);
        }
    }
    vector<vector<pair<ll, ll>>> g(n + 1);
    for(ll u = 1; u <= n; u++){
        for(const auto& p : a[u]){
            ll v = p.first;
            if (h[v]) {
                g[u].push_back(p);
            }
        }
    }
    vector<unordered_map<ll, ll>> m(n + 1);
    for(ll x : t){
        for(const auto& p : a[x]){
            ll y = c[p.first];
            m[x][y] += p.second;
        }
    }
    ll r = 0;
    for(const auto& p : e){
        ll u, v, w;
        tie(u, v, w) = p;
        if(c[u] != c[v]){
            r += w;
        }
    }
    for(ll i = 0; i < q; i++){
        ll v, y;
        cin>>v>>y;
        ll o = c[v];
        if(o == y){
            cout<<r<<endl;
            continue;
        }
        if(h[v]){
            r += m[v][o];
            r -= m[v][y];
        } 
        else{
            for(auto& p : a[v]){
                if (c[p.first] == o) r += p.second;
                if (c[p.first] == y) r -= p.second;
            }
        }
        for(auto& p : g[v]){
            ll x = p.first;
            ll w = p.second;
            m[x][o] -= w;
            m[x][y] += w;
        }
        c[v] = y;
        cout<<r<<endl;
    }
}

int main(){
    ll t; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
