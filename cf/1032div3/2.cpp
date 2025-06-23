#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n; cin>>n;
    string s; cin>>s;
    bool flg = false;
    set<char> st;
    for(int i =1;i<n-1;i++){
        if(st.find(s[i])!=st.end()){
            cout<<"YES"<<endl;
            return;
        }
        st.insert(s[i]);
    }
    if(st.find(s[0])!=st.end() || st.find(s[n-1])!=st.end()){
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