#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    set<int> st;
    
    for(int i = 1; i <= n; i++){
        st.insert(i);
    }
    
    auto it = st.begin();
    
    while(st.size() > 1){
        auto next_it = next(it);
        if(next_it == st.end()){
            next_it = st.begin();
        }
        cout << *next_it << " ";
        auto temp_it = next(next_it);
        if(temp_it == st.end()){
            temp_it = st.begin();
        }
        st.erase(next_it);
        it = temp_it;
        if(st.find(*it) == st.end()){
            it = st.begin();
        }
    }
    
    if(!st.empty()){
        cout << *st.begin();
    }
    
    cout << endl;
    return 0;
}
