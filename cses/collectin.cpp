#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    map<int,int> mp;
    for(int i = 0;i<n;i++){
        int x; cin>>x;
        mp[x]=i;
    }
    int cnt = 1;
    int limit = mp[1];
    for(auto x : mp){
        if(x.first==1)  continue;
        if(x.second<limit){
            cnt++;
            limit = x.second;
        }
        else{
            limit = x.second;
        }
    }
    cout<<cnt<<endl;
    return 0 ;
}