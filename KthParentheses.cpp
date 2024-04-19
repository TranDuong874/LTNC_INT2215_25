#include <bits/stdc++.h>

using namespace std;

string a[1000];
vector<string> ans;

void back_track(int n, int open, int close, string a[], int index){
    if(index >= 2*n){
        string tmp = "";
        for(int i = 0; i < 2*n; i++){
            tmp += a[i];
        }
        ans.push_back(tmp);
        return;
    }
    else{
        if(open < n){
            a[index] = "(";
            back_track(n, open+1, close, a, index+1);
        }
        if(close < open){
            a[index] = ")";
            back_track(n, open ,close + 1,a, index+1);
        }
    }
}

int main() {
    int n, k; cin >> n >> k;
    back_track(n/2, 0, 0, a, 0);
    // sort(ans.begin(), ans.end());
    cout << ans[k-1];
}
