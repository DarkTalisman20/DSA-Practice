#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e9+7;

ll binexp(ll x, ll y){
    ll res = 1;
    while(y>0){
        if(y%2==1)  res = ((res%M)*(x%M))%M ;
        x = ((x%M)*(x%M))%M ;
        y=y>>1;
    }
    return res;
}

int main(){
    //to find (a/b)%M we find modular inverse of b by finding (b^M-2)%M using binary exponentiation and then a*this mod m
    ll a, b;
    cin>>a>>b;
    ll d = binexp(b,(ll)(M-2));
    ll res = ((a%M)*d)%M;
    cout<<res<<'\n';
}