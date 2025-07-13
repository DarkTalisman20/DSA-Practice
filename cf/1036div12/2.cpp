#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    cout<<min(2*a[0],a[0]+a[1])<<endl;
}

int main(){
    int t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}