#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n; cin>>n;
    cout<<1<<" ";
    for(int i = n;i>2;i--){
        cout<<i<<" ";
    }
    cout<<2<<endl;
}

int main(){
    int t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}