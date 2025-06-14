#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    multiset<int> ms;
    for(int i= 0;i<n;i++){
        int a; cin>>a;
        if(ms.empty()){
            ms.insert(a);
        }
        else{
            auto it = ms.upper_bound(a);
            if(it==ms.end()){
                ms.insert(a);
            }
            else{
                ms.erase(it);
                ms.insert(a);
            }   
            
        }
        
    }
    cout<<ms.size()<<endl;
}