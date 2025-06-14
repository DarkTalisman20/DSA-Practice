#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n; 
    vector<int> a(n);
    for(int i =0;i<n;i++)   cin>>a[i];
    set<int> st;
    int l = 0, r = 0;
    int maxlen = 0;
    while(r<n){
        if(st.find(a[r])==st.end()){
            st.insert(a[r]);
            r++;
        }
        else{
            while(a[l]!=a[r]){
                st.erase(a[l]);
                l++;
            }
            l++;
            st.insert(a[r]);
            r++;
        }
        maxlen = max(maxlen,(r-l));
    }
    cout<<maxlen<<endl;
}