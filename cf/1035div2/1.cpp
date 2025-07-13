#include<bits/stdc++.h>
using namespace std;
using ll= long long;

void fn(){
    ll a,b,x,y; cin>>a>>b>>x>>y;
    if(b<a-1){
        cout<<-1<<endl;
    }
    else if(a==b+1 && a%2==0){
        cout<<-1<<endl;
    }
    else if(a==b+1 && a%2==1){
        cout<<y<<endl;
    }
    else{
        if(a==b){
            cout<<0<<endl;
        }
        else{
            ll res = 0;
            while(a!=b){
                if(a%2==0){
                    res += min(x,y);
                }
                else{
                    res+=x;
                }
                a++;
            }
            cout<<res<<endl;
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