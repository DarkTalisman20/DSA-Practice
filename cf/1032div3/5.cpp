#include<bits/stdc++.h>
using namespace std;

string l, r;
int len = 0;
int dp[20][2][2];

int fn1(int idx, bool lflg, bool rflg){
    if (idx == len) return 0;
    if (dp[idx][lflg][rflg] != -1) return dp[idx][lflg][rflg];
    int lb = (lflg == true) ? (l[idx] - '0') : 0;
    int rb = (rflg == true) ? (r[idx] - '0') : 9;
    int min_cost = 1e9;     
    for(int digit = lb; digit <= rb; digit++){
        int cst = 0;
        if(digit == (l[idx] - '0')) cst++;
        if(digit == (r[idx] - '0')) cst++;
        bool lflgtmp = lflg && (digit == lb);
        bool rflgtmp = rflg && (digit == rb);
        int next_cost = fn1(idx + 1, lflgtmp, rflgtmp);        
        min_cost = min(min_cost, cst + next_cost); 
    }    
    return dp[idx][lflg][rflg] = min_cost;
}

void fn(){
    cin>>l>>r;
    if(l>r){
        swap(l,r);
    }
    len = l.length();
    memset(dp, -1, sizeof(dp));
    cout<<fn1(0, true, true)<<endl;
}

int main(){
    int t = 1; 
    cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
