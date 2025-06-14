#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    int n, k; cin>>n>>k;
    if((n-k)==0){
        for(int i =0;i<n;i++){
            cout<<1;
        }
        cout<<endl;
    }
    else if((n-k)==1){
        for(int i = 0;i<n-1;i++){
            cout<<1;
        }
        cout<<0<<endl;
    }
    else if(k==0){
        for(int i = 0;i<n;i++){
            cout<<0;
        }
        cout<<endl;
    }
    else{
        int x = n-k;
        cout<<1;
        for(int i= 0;i<x-1;i++){
            cout<<0;
        }
        for(int i = 0;i<k-1;i++){
            cout<<1;
        }
        cout<<0<<endl;
    }
}

int main(){
    int t= 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}