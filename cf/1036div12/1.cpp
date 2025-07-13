#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n; cin>>n;
    vector<int> a(n),b(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin(),b.end());
    vector<int> res;
    for(int i = 0;i<n;i++){
        if(a[i]!=b[i]){
            res.push_back(a[i]);
        }
    }
    if(res.size()==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<res.size()<<endl;
        for(int i = 0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}