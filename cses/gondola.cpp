#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;
    vector<int> a(n);
    for(int i =0 ;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int l = 0; int r = n-1;
    int cnt = 0;
    while(l<r){
        if(a[l]+a[r]<=x){
            cnt++; l++; r--;
        }
        else{
            r--;
        }
    }
    cout<<n-cnt<<endl;
    return 0;
}