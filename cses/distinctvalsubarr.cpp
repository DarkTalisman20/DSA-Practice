#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)  cin>>v[i];
    ll l = 0, r = 0;
    ll cnt = 0;
    ll sum = 0;
    set<ll> st;
    while(r<n){
        if(st.find(v[r])==st.end()){
            st.insert(v[r]); cnt++; sum+=cnt;
            r++;
        }
        else{
            while(v[l]!=v[r]){
                st.erase(v[l]); l++; cnt--; 
            }
            l++;
            sum+=cnt;
            r++;
        }
    }
    cout<<sum<<endl;
    return 0;
}