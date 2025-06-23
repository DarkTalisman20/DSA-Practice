#include<bits/stdc++.h>
using namespace std;

void fn(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    for(int i = 0; i < n - 1; i++){
        if (abs(v[i] - v[i+1]) <= 1){
            cout << 0 << endl;
            return;
        }
    }

    int minops = INT_MAX;

    for (int i = 0; i < n; i++) {
        int right_direct = -1, right_smaller = -1, right_larger = -1;
        for(int j = i + 1; j < n; j++){
            if (abs(v[j] - v[i]) <= 1 && right_direct == -1) right_direct = j;
            if (v[j] > v[i] && right_larger == -1) right_larger = j;
            if (v[j] < v[i] && right_smaller == -1) right_smaller = j;
        }

        if(right_direct != -1){
           minops = min(minops, right_direct - i - 1);
        }
        if(right_smaller != -1 && right_larger != -1){
            int end_idx = max(right_smaller, right_larger);
            minops = min(minops, end_idx - i - 1);
        }
        if(i > 0){ 
            int left_direct = -1, left_smaller = -1, left_larger = -1;
            for(int j = i - 1; j >= 0; j--){
                if (abs(v[j] - v[i]) <= 1 && left_direct == -1) left_direct = j;
                if (v[j] > v[i] && left_larger == -1) left_larger = j;
                if (v[j] < v[i] && left_smaller == -1) left_smaller = j;
            }
            if(left_direct != -1){
                minops = min(minops, i - left_direct - 1);
            }
            if(left_smaller != -1 && left_larger != -1){
                int start_idx = min(left_smaller, left_larger);
                minops = min(minops, (i - 1) - start_idx);
            }
        }
    }

    if(minops == INT_MAX){
        cout<<-1<<'\n';
    }else{
        cout<<minops<<endl;
    }
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
