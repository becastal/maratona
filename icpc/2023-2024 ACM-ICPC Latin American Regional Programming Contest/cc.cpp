#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 4e5+10;
int F[MAX], FF[MAX];

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	if (k == 1) return cout << n << endl, 0;
	if (k > n) return cout << 0 << endl, 0;

	int res = 0;
	for (int t = k, c = 1; t <= n; t += k, c++) {
		auto add = [&](int a) {
			if (FF[F[a]]) --FF[F[a]];	
			++FF[++F[a]];
		};
		auto rem = [&](int a) {
			if (FF[F[a]]) --FF[F[a]];
			++FF[--F[a]];
		};
		int ok = 0;
		for (int i = 0; i < t; i++) {
			add(A[i]);
		}

		ok |= FF[c] == k;
		for (int i = t; i < n; i++) {
			rem(A[i-t]);
			add(A[i]);
			ok |= FF[c] == k;	
		}

		for (int i = n-t; i < n; i++) {
			rem(A[i]);
		}

		if (ok) res = t;
	}
	cout << res << endl;


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

