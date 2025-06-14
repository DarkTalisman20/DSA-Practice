#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n; 
    cin >> n; 
    string s; 
    cin >> s;    
    if(n == 1) {
        if(s[0] == '0') {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        return;
    }    
    int maxZeros = 0;
    int currentZeros = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            currentZeros++;
            maxZeros = max(maxZeros, currentZeros);
        } else {
            currentZeros = 0;
        }
    }    
    if(maxZeros > 3) {
        cout << "NO\n";
        return;
    }    
    string temp = s;
    bool found = true;
    while(found) {
        found = false;
        for(int i = 0; i <= (int)temp.length() - 4; i++) {
            if(temp.substr(i, 4) == "1001") {
                temp.erase(i, 4);
                found = true;
                break;
            }
        }
    }    
    int zeros = 0, ones = 0;
    for(char c : temp) {
        if(c == '0') zeros++;
        else ones++;
    }    
    if(zeros <= ones) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    int t = 1; 
    cin >> t;
    while(t--){
        fn();
    }
    return 0;
}
