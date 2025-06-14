#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    int n; cin>>n;
    unordered_map<int,int> mp;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x; cin>>x; mp[x]++; v.push_back(x);
    }
    int maincnt = 0;
    int cnt = mp.size();
    int ptr = n-1;
    unordered_set<int> s;
    while(ptr>=0){
        mp[v[ptr]]--; 
        if(s.find(v[ptr])==s.end()){
            s.insert(v[ptr]);
            cnt--;
        }
        if(mp[v[ptr]]==0){
            mp.erase(v[ptr]);
        }
        if(cnt==0){
            maincnt++;
            cnt = mp.size();
            s.clear();
        }
        ptr--;
    }
    cout<<maincnt<<endl;
}

int main(){
    int t =1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}