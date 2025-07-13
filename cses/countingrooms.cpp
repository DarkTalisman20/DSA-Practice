#include<bits/stdc++.h>
using namespace std;

int n,m; 
vector<vector<char>> grid;
vector<pair<int,int>> fl;
vector<vector<int>> mp;

void dfs(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || mp[i][j] == 1 || grid[i][j] == '#'){
        return;
    }                       
    mp[i][j] = 1;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}


int main(){
    cin>>n>>m;
    grid.resize(n);
    mp.resize(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char ch; cin>>ch;
            grid[i].push_back(ch);
            mp[i].push_back(0);
            if(ch=='.'){
                fl.push_back({i,j});
            }
        }
    }

    int z= fl.size();
    int cnt = 0;
    for(int i = 0;i<z;i++){
        if(mp[fl[i].first][fl[i].second]==0){
            dfs(fl[i].first,fl[i].second);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}