#include<bits/stdc++.h>
using namespace std;

vector<int> p,r;

bool comp(const tuple<int,int,int> a, const tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}

int find(int x){
    int y = x;
    while(y!=p[y]){
        y =p[y];
    }
    while(x!=p[x]){
        int z = p[x];
        p[x] = y;
        x = z;
    }
    return x;
}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(r[x]>r[y]) swap(x,y);
    p[x] = y;
    if(r[x]==r[y])  r[y]++;
}

int main(){
    ifstream ip("wormsort.in");
    ofstream op("wormsort.out");
    int n,m; ip>>n>>m;
    vector<int> v(n+1);
    for(int i = 1;i<=n;i++){
        ip>>v[i];
    }
    vector<tuple<int,int,int>> edg(m+1);
    for(int i = 1;i<=m;i++){
        int a,b,c; ip>>a>>b>>c;
        get<0>(edg[i]) = a;
        get<1>(edg[i]) = b;
        get<2>(edg[i]) = c;
    }
    bool flg = true;
    for(int i = 1;i<=n;i++){
        if(v[i]!=i){
            flg = false;
            break;
        }
    }
    if(flg==true){
        op<<-1<<endl;
        return 0;
    }
    sort(edg.begin()+1,edg.end(),comp);
    // for(int i = 1;i<=m;i++){
    //     op<<get<0>(edg[i])<<" "<<get<1>(edg[i])<<" "<<get<2>(edg[i])<<endl;
    // }
    // p.resize(n+1); r.resize(n+1,1);
    // for(int i = 1;i<=n;i++){
    //     p[i] = i;
    // }
    p.resize(n+1);
    r.resize(n+1);
    int lt = 1, rt = m;
    int res = -1;
    while(lt<=rt){
        int md = lt + (rt-lt)/2;
        fill(r.begin(),r.end(),1);
        for(int i = 1;i<=n;i++){
            p[i] = i;
        }
        for(int i = md;i<=m;i++){
            unite(get<0>(edg[i]), get<1>(edg[i]));
        }
        bool flg = true;
        for(int i = 1;i<=n;i++){
            if(find(i)!=find(v[i])){
                flg=false;
                break;
            }
        }
        if(flg==true){
            res= get<2>(edg[md]);
            lt = md+1;
        }
        else{
            rt = md-1;
        }
    }
    op<<res<<endl;
}