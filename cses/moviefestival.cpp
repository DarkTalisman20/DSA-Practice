#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second<b.second;
}

int main(){
    int n; cin>>n;
    vector<pair<int,int>> sc(n);
    for(int i= 0;i<n;i++){
        cin>>sc[i].first>>sc[i].second;
    }
    sort(sc.begin(),sc.end(),comp);
    int cnt =1, bar =sc[0].second;
    for(int i = 1; i<n;i++){
        if(sc[i].first<bar){
            continue;
        }
        else{
            bar = sc[i].second; cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}