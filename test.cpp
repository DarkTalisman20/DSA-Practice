#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll bin; cin>>bin;
    int n; cin>>n;
    vector<tuple<ll,ll,string>> v(n);
    for(int i = 0;i<n;i++){
        char ch;
        cin>>get<0>(v[i])>>ch>>get<1>(v[i])>>ch>>get<2>(v[i]);
    }
    sort(v.begin(),v.end());
    get<0>(v[0]) = 0;
    vector<int> idx;
    idx.push_back(0);
    ll maxr,minr;
    minr = 0;
    maxr = get<1>(v[0]);
    unordered_set<int> s;
    for(int i =1;i<n;i++){
        if(get<0>(v[i])>minr && get<1>(v[i])<maxr){
            s.insert(i);
        }
        else{
            minr = get<0>(v[i]); maxr = get<1>(v[i]);
            idx.push_back(i);
        }
    }
    int z = idx.size();
    get<1>(v[idx[z-1]]) = 9999999999;
    if(z>=2){
        for(int i = 0;i<z-1;i++){
            get<1>(v[idx[i]]) = max(get<0>(v[idx[i+1]])-1,get<1>(v[idx[i]]));
        }
    }
    string comp = get<2>(v[0]);
    vector<ll> st,en;
    vector<string> cp;
    st.push_back(get<0>(v[0]));
    en.push_back(get<1>(v[0]));
    cp.push_back(get<2>(v[0]));
    for(int i = 1;i<n;i++){
        int x = en.size();
        string r = get<2>(v[i]);
        if(r==comp){
            en[x-1] = max(en[x-1],get<1>(v[i]));
        }
        else{
            if(s.find(i)!=s.end()){
                st.push_back(get<0>(v[i]));
                en.push_back(get<1>(v[i]));
                cp.push_back(get<2>(v[i]));
            }
            else{
                st.push_back(get<0>(v[i]));
                en.push_back(get<1>(v[i]));
                cp.push_back(get<2>(v[i]));
                comp = get<2>(v[i]);
            }
        }
    }
    int y = st.size();
    cout<<bin<<"0000000000"<<','<<bin<<en[0]<<','<<cp[0]<<endl;
    for(int i = 1;i<y;i++){
        cout<<bin<<st[i]<<','<<bin<<en[i]<<','<<cp[i]<<endl;
    }
    return 0;
}