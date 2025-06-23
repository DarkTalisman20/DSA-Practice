#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SparseTable{
    ll n;
    vector<vector<ll>> st;
    vector<ll> log;
    SparseTable(const vector<ll>& arr){
        n = (ll)arr.size();
        log.resize(n + 1);
        log[1] = 0;
        for (ll i = 2; i <= n; i++){
            log[i] = log[i/2] + 1;
        }
        ll k = log[n];
        st.assign(n, vector<ll>(k + 1));
        for (ll i = 0; i < n; i++){
            st[i][0] = arr[i];
        } 
        for(ll j = 1; j <= k; j++){
            for(ll i = 0; i + (1<<j) <= n; i++){
                st[i][j] = max(st[i][j - 1], st[i + (1<<(j-1))][j-1]);
            }
        }
    }
    ll query(ll L, ll R){
        ll j = log[R - L + 1];
        return max(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

void fn(){
    ll n, s, x;
    cin >> n >> s >> x;
    vector<ll> v(n);
    for(ll &val : v) cin>>val;
    vector<ll> prefix(n);
    prefix[0] = v[0];
    for(ll i = 1; i < n; i++) prefix[i] = prefix[i-1] + v[i];
    SparseTable st(v);
    unordered_map<ll, vector<ll>> mp;
    mp.reserve(n);
    mp[0].emplace_back(-1);
    ll cnt = 0;
    for(ll i = 0; i < n; i++){
        ll target = prefix[i] - s;
        if(mp.count(target)){
            for(const ll& startIdx : mp[target]){
                ll l = startIdx + 1, r = i;
                if(l > r) continue;
                ll maxval = st.query(l, r);
                if(maxval == x){
                    cnt++;
                }
            }
        }
        mp[prefix[i]].push_back(i);
    }
    cout << cnt << "\n";
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; 
    cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
