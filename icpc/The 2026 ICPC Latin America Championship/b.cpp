#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<array<int, 2>> R;
	auto sw = [&](int j, int i) {
		int s = A[j] + A[i];
		A[i] = (s + 1) / 2, A[j] = s / 2;
		R.push_back({j + 1, i + 1});
	};

	while (!is_sorted(all(A))) {
		for (int i = n-1; i >= 0; i--) {
			int mx = -1, pos = -1;
			for (int j = 0; j < i; j++) {
				if (mx < A[j]) {
					mx = A[j];
					pos = j;
				}
			}
			if (pos != -1) {
				sw(pos, i);
			}
		}
	}
	assert(R.size() <= 1e5);

	//cout << "A: ";
	//for (int i = 0; i < n; i++) {
	//	cout << A[i] << " \n"[i==n-1];
	//}

	cout << R.size() << endl;
	for (auto [i, j] : R) {
		cout << i << ' ' << j << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
