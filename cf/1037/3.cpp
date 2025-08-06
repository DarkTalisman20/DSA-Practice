#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    ll n,k; cin>>n>>k;
    vector<ll> h(n);
    for(ll i = 0;i<n;i++){
        cin>>h[i];
    }
    set<ll> st;
    st.insert(h[k-1]);
    for(ll i = 0;i<n;i++){
        if(h[i]>h[k-1]){
            st.insert(h[i]);
        }
    }
    ll hw = 1;
    ll hi = h[k-1];
    if(hw>hi){
        cout<<"NO"<<endl;
        return;
    }
    while(true){
        if(st.size()==1){
            cout<<"YES"<<endl;
            return;
        }
        auto it = st.begin();
        ++it;
        ll hnext = *it;
        ll diff = hnext - hi;
        if(hw+diff-1 > hi){
            cout<<"NO"<<endl;
            return;
        }
        else{
            hw += hnext - hi;
            hi = hnext;
            st.erase(st.begin());
        }
    }
}

int main(){
    ll t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
