#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int h, w, n; cin >> h >> w >> n;
	vector<int> H(n), W(n);
	for (int i = 0; i < n; i++) {
		cin >> H[i] >> W[i];
	}

	vector<int> Oh(n), Ow(n);
	iota(all(Oh), 0);
	iota(all(Ow), 0);

	sort(all(Oh), [&](int a, int b) {
		return H[a] > H[b];
	});
	sort(all(Ow), [&](int a, int b) {
		return W[a] > W[b];
	});

	vector<int> Rh(n), Rw(n), foi(n);

	for (int t = 0, i = 0, j = 0; t < n; t++) {
		while (i < n and foi[Oh[i]]) i++;
		while (j < n and foi[Ow[j]]) j++;

		int p;
		if (i < n && H[Oh[i]] == h) p = Oh[i];
		else p = Ow[j];

		Rh[p] = h - H[p] + 1;
		Rw[p] = w - W[p] + 1;
		foi[p] = 1;

		if (H[p] == h) {
			w -= W[p];
		} else {
			h -= H[p];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << Rh[i] << ' ' << Rw[i] << endl;
	}

	return 0;
}

signed main() {
	_;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
