#include<bits/stdc++.h>
using namespace std;

void fn(){
    int x; cin>>x;
    int mindig = INT_MAX;
    while(x>0){
        mindig = min(mindig,(x%10));
        x/=10;
    }
    cout<<mindig<<endl;
}

int main(){
    int t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}