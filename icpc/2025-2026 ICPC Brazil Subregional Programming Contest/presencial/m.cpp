#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);


	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	if (k == 1) {
		return cout << k + *min_element(A.begin(), A.end()) << endl, 0;
	}

	vector<int> min_pre(A), min_suf(A);
	for (int i = 1; i < n; i++) {
		min_pre[i] = min(min_pre[i-1], min_pre[i]);
	}
	for (int i = n-2; i >= 0; i--) {
		min_suf[i] = min(min_suf[i+1], min_suf[i]);
	}

	int off = 0;
	map<int, int> F;
	auto add = [&](int i) {
		F[A[i] + ++off + k]++;	
		//cout << "~~~~~~~~~" << endl;
		//cout << i << endl;
		//for (auto [a, b] : F) cout << a << ' ' << b << endl;
	};
	auto rem = [&](int i) {
		int val = A[i] + i + 1 + k;	
		if (--F[val] == 0) F.erase(val);
	};
	auto calc = [&](int l, int r) {
		int mnpre = l ? min_pre[l - 1] : INT_MAX;
		int mnsuf = r + 1 < n ? min_suf[r + 1] : INT_MAX;

		return min({mnpre, mnsuf, F.begin()->first - off});
	};

	int res = INT_MIN;
	for (int i = 0; i < k; i++) {
		add(i);
		res = max(res, calc(0, i));
	}

	for (int i = k; i < n; i++) {
		add(i);
		rem(i - k);
		res = max(res, calc(i-k, i)) << endl;
	}
	cout << res << endl;

	return 0;
}
