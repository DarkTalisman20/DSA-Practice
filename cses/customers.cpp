#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n),b(n);
    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int p1 = 0, p2 = 0;
    int cnt = 0, maxcnt = 0;
    while(p1<n && p2<n){
        if(a[p1]<b[p2]){
            cnt++; p1++;
        }
        else{
            p2++; cnt--;
        }
        maxcnt = max(maxcnt,cnt);
    }
    cout<<maxcnt<<endl;
    return 0;
}