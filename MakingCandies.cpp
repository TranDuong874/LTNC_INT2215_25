#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check (ll machines, ll workers, ll price, ll n, ll rounds) {
	//	Kiểm tra xem số lượng machines hiện tại có lớn hơn lượng machines cần thiết để tạo ra đủ số kẹo trong n rounds không 
	if (machines >= (n + workers - 1) / workers) return true; 

	//	Khởi tạo current là số kẹo làm được trong một ca
	ll current = machines * workers;
	rounds--;

	if (rounds == 0) return false;

	while (true) {
		//	Số lượng kẹo còn lại phải làm
		ll remaining = n - current;

		//	rnds là số ca cần phải làm để cho đủ số kẹo còn lại
		ll rnds = (remaining + machines * workers - 1) / (machines * workers);
		if (rnds <= rounds) return true; // Nếu số ca cần làm đủ mà ít hơn số ca đang xét thì trả về true

		//	Nếu số kẹo hiện tại ít hơn số kẹo cần bán
		if (current < price) {
			remaining = price - current; //	Số kẹo cần thiết để mua một machine hoặc worker
			rnds = (remaining + machines * workers - 1) / (machines * workers); // Số round cần thiết để kiếm đủ kẹo mua thêm machine hoặc worker

			rounds -= rnds; // Sau khi tính toán được số round cần thiết để mua thêm MỘT machine/worker, ta sẽ nhảy qua số 'rnds' rounds đó
			if (rounds < 1) return false;

			current += rnds * machines * workers; // và cộng thêm số kẹo mua được sau khi đã nhảy qua 'rnds' rounds
		}

		current -= price; // Trừ đi số kẹo đã bán

		// Chúng ta nhảy qua 'rnds' rounds chỉ để kiếm đủ tiền mua một machines/workers ở mỗi vòng lặp
		if (machines > workers) {
			workers++;
		} else {
			machines++;
		}
	}
	return false;
}


int main(){
	ll m, w, p, n; cin >> m >> w >> p >> n;
	ll lo = 1, hi = 1e18;

	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (check(m, w, p, n, mid)) { // Hàm này kiểm tra xem số ca hiện tại có hợp lệ không
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}

	cout << lo;

}
