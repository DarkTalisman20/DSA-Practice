#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    multiset<int> h;
    for(int i = 0;i<n;i++){
        int v; cin>>v; 
        h.insert(v);
    }
    vector<int> t(m);
    for(int i = 0;i<m;i++){
        cin>>t[i];
    }
    for(int i = 0;i<m;i++){
        int x = t[i];
        auto it = h.upper_bound(x);
        if(it==h.begin()){
            cout<<-1<<endl;
            continue;
        }
        else{
            cout<<*(--it)<<endl;
            h.erase(it);
        }
    }
    return 0;
}