#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	stack<int> S;
	vector<int> L(n), R(n);

	for (int i = 0; i < n; i++) {
		while (S.size() and A[S.top()] <= A[i]) S.pop();
		L[i] = (S.size() ? S.top() : -1);
		S.push(i);
	}

	while (S.size()) S.pop();
	for (int i = n-1; i >= 0; i--) {
		while (S.size() and A[S.top()] < A[i]) S.pop();
		R[i] = (S.size() ? S.top() : n);
		S.push(i);
	}

	int q; cin >> q;
	while (q--) {
		int m; cin >> m;
		vector<int> B(m);
		for (int& i : B) {
			cin >> i, i--;
		}

		vector<array<int, 2>> C;
		for (int i = 0, ult = -1; i < m; i++) {
			int b = B[i];

			vector<int> agr;
			while (b != -1 and L[b] > ult) {
				agr.push_back(L[b]);
				b = L[b];
			}

			for (int j = (int)agr.size()-1; j >= 0; j--) {
				C.push_back({agr[j], 0});
			}

			C.push_back({B[i], 1});
			ult = C.back()[0];
		}

		//for (int i = 0; i < m; i++) {
		//	if (C.size() and C.back()[0] < L[B[i]]) {
		//		C.push_back({L[B[i]], 0});
		//	}
		//	C.push_back({B[i], 1});
		//}

		ll res = 0;
		for (auto [i, c] : C) {
			int pa = lower_bound(all(B), i) - B.begin(),
				pb = upper_bound(all(B), i) - B.begin(),
				l = upper_bound(all(B), L[i]) - B.begin(),
				r = lower_bound(all(B), R[i]) - B.begin();

			int a = pa - l, b = r - pb;
			ll add = 1LL * A[i] * a * b;
			if (c) add += 1LL * A[i] * (1 + a + b);
			res += add;
			// cout << "A[i] = " << A[i] << " | (" << a << ", " << b << "), val = " << add << endl;
			//  res += (quantos em B > L[i] e < i) *
			//		   (quantos em B < R[i] and > i) * A[i];
			// esses sao os que passam por mim, ainda tem os que eu sou o meio
		}
		cout << res << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
