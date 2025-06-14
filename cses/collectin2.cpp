#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,q; cin>>n>>q;
    vector<ll> v(n+1);
    vector<ll> mp(n+1);
    for(ll i = 0;i<n;i++){
        ll a; cin>>a; v[i]= a; mp[a]=i;
    }
    ll cnt = 1; ll limit = mp[1];
    for(ll i =2;i<=n;i++){
        if(mp[i]<limit){
            cnt++;
        }
        limit = mp[i];
    }
    //cout<<cnt<<endl;
    for(ll i= 0;i<q;i++){
        ll a,b; cin>>a>>b; a--; b--;
        set<pair<ll,ll>> st;
        if(v[a]>1) st.insert({v[a]-1,v[a]});
        if(v[a]<n) st.insert({v[a],v[a]+1});
        if(v[b]>1) st.insert({v[b]-1,v[b]});
        if(v[b]<n) st.insert({v[b],v[b]+1});
        for(auto x : st){
            if(mp[x.first]>mp[x.second])    cnt--;
        }
        swap(mp[v[a]],mp[v[b]]);
        swap(v[a],v[b]);
        for(auto x : st){
            if(mp[x.first]>mp[x.second])    cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}