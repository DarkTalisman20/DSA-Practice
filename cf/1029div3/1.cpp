#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    int flag = 0;
    int first = -1; int last = -1;
    for(int i = 0;i<n;i++){
        if(a[i]==1 && flag == 0){
            flag = 1;first = i; last = first;
        }
        else if(a[i]==1){
            last = i;
        }
        else{
            continue;
        }
    }
    if((last-first+1)<=k){
        cout<<"YES"<<endl;
    }
    else{
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