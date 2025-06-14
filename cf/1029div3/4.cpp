#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    ll n; 
    cin >> n;
    vector<ll> a(n);
    for(ll i= 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        if(a[0] > 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    ll denom = n + 1;
    if((2*a[0] - a[1]) % denom != 0){
        cout << "NO" << endl;
        return;
    }
    ll y = (2*a[0] - a[1]) / denom;
    ll x = a[0] - n*y;
    if(x < 0 || y < 0){
        cout << "NO" << endl;
        return;
    }
    bool valid = true;
    for(ll i = 0; i < n; i++){
        ll exp = x*(i+1) + y*(n-i);
        if(a[i] != exp){
            valid = false;
            break;
        }
    }
    if(valid){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    ll t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}