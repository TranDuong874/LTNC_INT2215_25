#include <bits/stdc++.h> 

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> house;

    
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        house.push_back(tmp);
    }

    sort(house.begin(), house.end());

    int router_pos = house[0];
    int router_count = 0;
    int possible_pos = house[0] + k;


    for (int i = 0; i < n; i++) {
    	if (house[i] > possible_pos) {
    		router_count++;
    		router_pos = house[i-1];

    		while (i < n && house[i] <= router_pos + k) {
    			i++;
    		}

    		possible_pos = house[i] + k;
    	}
    	if (i == n - 1) {
    		router_count++;
    	}

    }

    cout << router_count;

}
