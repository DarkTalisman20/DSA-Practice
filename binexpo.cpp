/*
idea is that if kth bit of b in binary exponentiation is 1 then you multiply the result with 3^(k1)
a = 3 b = 11
num = 3^11 = 3^(1+2+8)
res = 1
b = 11 = (1011)2
1st itr
res = res*a = 3
a = 3^2
b = 101
2nd itr
res = res*a = 3*(3^2)
a = 3^4
b = 10
3rd itr
a = 3^8
b = 1
4th itr
res = res*q = (3)*(3^2)*(3^8)
a = 3^16
b = 0
end
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a ,b; cin>>a>>b;
    ll res = 1;
    while(b>0){
        if(b%2==1)  res *= a;
        a *= a; // this is the a^(k1) wala term
        b = b>>1;
    }    
    cout<<res<<'\n';
    return 0;
}