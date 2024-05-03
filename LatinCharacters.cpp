#include <bits/stdc++.h>

using namespace std;


void recur(string word, int index, int k, int length, char low, char high, int dst) {
    if (high - low > dst) return;
    if (index == length) {
        if (high - low <= dst) {
            cout << word << endl;
        }
        
        return;
    } else {
        for (int i = 0; i < k; i++) {
            char tmp = 'a' + i;

            recur(word + tmp, index + 1, k, length, min(tmp, low), max(tmp, high), dst);
        }
    }
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    recur("", 0, n, m, 'z', 'a', k);
}
