#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,q; cin>>n>>q;
    set<ll> mp;
    mp.insert(n); mp.insert(0);
    multiset<ll> st; st.insert(n);
    for(ll i = 0;i<q;i++){
        ll x; cin>>x;
        auto it = mp.upper_bound(x);
        ll ub = (*it), lb = (*(--it));
        st.erase(st.find(ub-lb));
        st.insert(ub-x); st.insert(x-lb);
        mp.insert(x);
        cout<<*st.rbegin()<<'\n';
    }
    return 0;
}