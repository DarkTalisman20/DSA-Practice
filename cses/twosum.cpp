#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin>>n>>x;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v.push_back({a,i+1});
    }
    sort(v.begin(),v.end());
    int l = 0, r= n-1;
    while(l<r){
        int y = v[l].first + v[r].first;
        if(y==x){
            cout<<v[l].second<<" "<<v[r].second<<endl;
            return 0;
        }
        else if(y<x){
            l++;
        }
        else{
            r--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}