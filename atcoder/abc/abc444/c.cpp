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
	sort(all(A));

	auto da = [&](int x) {
		int p = n-1;
		for (; p >= 0 and A[p] == x; p--);

		if (p & 1 ^ 1) return;
		for (int i = 0, j = p; i < j; i++, j--) {
			if (A[i] + A[j] != x) {
				return;
			}
		}

		cout << x << ' ';
	};

	da(A[n-1]);
	da(A[n-1] + A[0]);
	cout << endl;

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

