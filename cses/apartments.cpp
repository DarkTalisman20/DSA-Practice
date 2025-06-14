#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(n),b(m);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<m;i++){
        cin>>b[i];
    }
    sort(a.rbegin(),a.rend()); sort(b.rbegin(),b.rend());
    int p1 = 0, p2 = 0;
    int cnt = 0;
    while(p1<n && p2<m){
        if(b[p2]>=(a[p1]-k) && b[p2]<=(a[p1]+k)){
            cnt++; p2++; p1++;
        }
        else if(b[p2]>(a[p1]+k)){
            p2++;
        }
        else{
            p1++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
