#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    int n; cin >> n;
    vector<ll> p(n), s(n);
    for(int i = 0; i < n; i++) cin>>p[i];
    for(int i = 0; i < n; i++) cin>>s[i];
    if(n == 1){
        if(p[0] == s[0]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        return;
    }
    bool flg = true;
    if (s[0] != p[n - 1]) {
        flg = false;
    }
    for(int i = 1; i < n && flg; i++){
        if(p[i-1] % p[i] != 0){
            flg = false;
        }
    }
    for(int i = n - 2; i >= 0 && flg; i--){
        if(s[i+1] % s[i] != 0){
            flg = false;
        }
    }
    if(!flg){
        cout<<"NO"<<endl;
        return;
    }
    ll a, b, g;
    a = p[0]; b = s[1];
    while(b){ 
        a %= b; 
        swap(a, b); 
    }
    if(a != s[0]){
        flg = false;
    }
    if(flg==true){
        a = p[n-2]; b = s[n-1];
        while(b){ 
            a %= b; 
            swap(a, b); 
        }
        if(a != p[n-1]){
            flg = false;
        }
    }
    for(int i = 1; i < n - 1 && flg; ++i){
        a = p[i]; b = s[i];
        while(b){
            a %= b; 
            swap(a, b); 
        }
        g = a;
        a = p[i-1]/p[i];
        b = s[i]/g;
        while(b){ 
            a %= b; 
            swap(a, b); 
        }
        if(a != 1){
            flg = false;
            continue;
        }
        a = p[i]/g;
        b = s[i+1]/s[i];
        while(b){
            a %= b; 
            swap(a, b); 
        }
        if(a != 1){
            flg = false;
        }
    }

    if(flg){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    int t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
