#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n,m; cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }
    
    int max1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            max1 = max(max1, v[i][j]);
        }
    }
    
    vector<pair<int,int>> ps;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == max1){
                ps.push_back({i,j});
            }
        }
    }
    
    if(ps.size() == 1){
        cout<<max1-1<<endl;
        return;
    }
    
    map<int, unordered_set<int>> row_to_cols;
    map<int, unordered_set<int>> col_to_rows;
    set<int> rows, cols;
    
    for(auto &p : ps){
        row_to_cols[p.first].insert(p.second);
        col_to_rows[p.second].insert(p.first);
        rows.insert(p.first);
        cols.insert(p.second);
    }
    
    bool flg = false;
    for(int x : rows){
        for(int y : cols){
            bool valid = true;
            for(int r : rows){
                if(r == x) continue;
                if(row_to_cols[r].size() != 1 || *row_to_cols[r].begin() != y){
                    valid = false;
                    break;
                }
            }
            if(!valid) continue;
            
            for(int c : cols){
                if(c == y) continue;
                if(col_to_rows[c].size()!=1 || *col_to_rows[c].begin() != x){
                    valid = false;
                    break;
                }
            }
            
            if(valid==true){
                flg=true;
                break;
            }
        }
        if(flg==true) break;
    }
    
    if(flg==true){
        cout<<max1-1<<endl;
    }else{
        cout<<max1<<endl;
    }
}


int main(){
    int t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
