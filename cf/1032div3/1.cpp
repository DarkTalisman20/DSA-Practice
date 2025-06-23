#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n,s; cin>>n>>s;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    int mn = v[0], mx = v[n-1];
    if(n==1){
        cout<<abs(mn-s)<<endl;
    }
    else if(s>=mn && s<=mx){
        int dist1 = abs(s-mn);
        int dist2 = abs(mx-s);
        if(dist1<=dist2){
            cout<<2*dist1 + dist2<<endl;
        }
        else{
            cout<<2*dist2 + dist1<<endl;
        }
    }
    else{
        if(s>mx){
            cout<<s-mn<<endl;
        }
        else if(s<mn){
            cout<<mx-s<<endl;
        }
    }
}

int main(){
    int t= 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}