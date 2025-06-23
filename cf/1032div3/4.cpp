#include <bits/stdc++.h>
using namespace std;

void fn(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    vector<pair<int, int>> ops;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            swap(a[i], b[i]);
            ops.push_back({3, i + 1});
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j + 1 < n; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                ops.push_back({1, j+1});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j+1<n; j++){
            if(b[j]>b[j + 1]){
                swap(b[j], b[j + 1]);
                ops.push_back({2, j + 1});
            }
        }
    }

    cout<<ops.size()<<endl;
    for(auto op : ops){
        cout<<op.first<<" "<<op.second<<endl;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
