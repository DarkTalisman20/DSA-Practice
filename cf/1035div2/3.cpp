#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    ll n,l,r,k; cin>>n>>l>>r>>k;
    if(n%2==1){
        cout<<l<<endl;
    }
    else if(n==2){
        if(l==0 && r==0){
            cout<<0<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    else{
        ll x = 1;
        while(x<=l){
            x = x<<1;
        }
        if(x>r){
            cout<<-1<<endl;
        }
        else{
            if(k==n-1 || k==n){
                cout<<x<<endl;
            }
            else{
                cout<<l<<endl;
            }
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

