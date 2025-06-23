#include<bits/stdc++.h>
using namespace std;

void fn(){
    int a,x,y;
    cin>>a>>x>>y;
    if(x>y) swap(x,y);
    if(a>=x && a<=y){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}

int main(){
    int t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}