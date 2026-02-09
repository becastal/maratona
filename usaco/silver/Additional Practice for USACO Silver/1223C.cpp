#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		i /= 100;
	}

	int x, a; cin >> x >> a;
	int y, b; cin >> y >> b;
	ll k; cin >> k;

	vector<int> C(n+1);
	for (int i = a; i <= n; i += a) {
		C[i] += x;
	}
	for (int i = b; i <= n; i += b) {
		C[i] += y;
	}

	sort(rall(A));
	auto da = [&](int m) {
		priority_queue<int> pq;
		for (int i = 1; i <= m; i++) if (C[i]) {
			pq.push(C[i]);	
		}

		ll agr = 0, p = 0;
		while (pq.size()) {
			agr += 1LL * pq.top() * A[p++];
			pq.pop();
		}
		//cout << m << ' ' << agr << endl;
		return agr >= k;
	};

	int l = 1, r = n, res = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			r = m - 1;
			res = m;
		} else {
			l = m + 1;	
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

