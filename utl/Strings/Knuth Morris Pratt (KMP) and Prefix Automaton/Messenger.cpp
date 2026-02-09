#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	vector<array<int, 2>> A(n), B(m);

	for (auto& [a, b] : A) {
		char c;	cin >> a >> c >> c;
		b = c - 'a';
	}

	for (auto& [a, b] : B) {
		char c;	cin >> a >> c >> c;
		b = c - 'a';
	}

	vector<array<int, 2>> A_, B_;
	for (auto [a, b] : A) {
		if (A_.size() and A_.back()[1] == b) {
			A_.back()[0] += a;
		} else {
			A_.push_back({a, b});
		}
	}
	A = move(A_);

	for (auto [a, b] : B) {
		if (B_.size() and B_.back()[1] == b) {
			B_.back()[0] += a;
		} else {
			B_.push_back({a, b});
		}
	}
	B = move(B_);

	n = (int)A.size(), m = (int)B.size();
	int res = 0;
	if (m == 1) {
		for (auto [a, b] : A) if (b == B[0][1]) {
			res += max(0LL, a - B[0][0] + 1);			
		}
	} else if (m == 2) {
		for (int i = 1; i < n; i++) {
			auto [ai, bi] = A[i-1];
			auto [aj, bj] = A[i];
			res += (bi == B[0][1] and ai >= B[0][0]) and (bj == B[1][1] and aj >= B[1][0]);
		}
	} else {
		vector<int> Pos;
		auto Bm = B;
		Bm.erase(Bm.begin());
		Bm.pop_back();
		int k = m - 2;

		vector<int> P(k);
		for (int i = 1, j = 0; i < k; i++) {
			while (j and Bm[j] != Bm[i]) j = P[j-1];	
			P[i] = (j += Bm[j] == Bm[i]);
		}

		for (int i = 0, j = 0; i < n; i++) {
			while (j and Bm[j] != A[i]) j = P[j-1];
			j += (Bm[j] == A[i]);
			if (j == k) Pos.push_back(i - k + 1), j = P[j-1];
		}

		for (int l : Pos) {
			int r = l + k;

			if (l >= 1 and r< n) {
				auto [ai, bi] = A[l-1];
				auto [aj, bj] = A[r];
				res += (bi == B[0][1] and ai >= B[0][0]) and (bj == B[m-1][1] and aj >= B[m-1][0]);
			}
		}
	}
	cout << res << endl;

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
