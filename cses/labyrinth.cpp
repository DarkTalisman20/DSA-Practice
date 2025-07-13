#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
pair<int,int> st, en;
vector<vector<pair<int,int>>> parent;
vector<vector<int>> vis;

int main(){
    int n,m; cin>>n>>m;
    grid.resize(n);
    parent.resize(n);
    vis.resize(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char ch; cin>>ch;
            grid[i].push_back(ch);
            parent[i].push_back({-1,-1});
            vis[i].push_back(0);
            if(ch=='A'){
                st.first = i; st.second = grid[i].size()-1;
            }
            if(ch=='B'){
                en.first = i; en.second= grid[i].size()-1;
            }
        }
    }
    bool flg = false;
    queue<pair<int,int>> q;
    q.push({st.first,st.second});
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(x.first==en.first && x.second==en.second){
            flg = true;
            break;
        }
        if(x.first+1<n && x.second>=0 && vis[x.first+1][x.second]==0 && grid[x.first+1][x.second]!='#'){
            parent[x.first+1][x.second] = {x.first,x.second};
            vis[x.first+1][x.second] = 1;
            q.push({x.first+1,x.second});
        }
        if(x.second+1<m && x.first>=0 && vis[x.first][x.second+1]==0 && grid[x.first][x.second+1]!='#'){
            parent[x.first][x.second+1] = {x.first,x.second};
            vis[x.first][x.second+1] = 1;
            q.push({x.first,x.second+1});
        }
        if(x.first-1>=0 && x.second<m && vis[x.first-1][x.second]==0 && grid[x.first-1][x.second]!='#'){
            parent[x.first-1][x.second] = {x.first,x.second};
            vis[x.first-1][x.second] = 1;
            q.push({x.first-1,x.second});
        }
        if(x.first<n && x.second-1>=0 && vis[x.first][x.second-1]==0 && grid[x.first][x.second-1]!='#'){
            parent[x.first][x.second-1] = {x.first,x.second};
            vis[x.first][x.second-1] = 1;
            q.push({x.first,x.second-1});
        }
    }
    if(flg==false){
        cout<<"NO"<<endl;
    }
    else{
        string pt;
        int x = en.first, y = en.second;
        while(x!=st.first || y!= st.second){
            int a = parent[x][y].first;
            int b = parent[x][y].second;
            if(a==x && b==y-1){
                pt.push_back('R');
            }
            else if(a==x && b==y+1){
                pt.push_back('L');
            }
            else if(a==x-1 && b==y){
                pt.push_back('D');
            }
            else if(a==x+1 && b==y){
                pt.push_back('U');
            }
            x = a; y = b;
        }
        reverse(pt.begin(),pt.end());
        cout<<"YES"<<endl;
        cout<<pt.length()<<endl;
        cout<<pt<<endl;
    }
    return 0;
}