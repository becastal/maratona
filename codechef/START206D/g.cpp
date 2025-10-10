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
	for (int& i : A) cin >> i;

	vector<int> ult(n);
	for (int i = n-1; i >= 0; i--) {
		if (A[i] == 1) {
			if (i == n-1) ult[i] = i;
			else ult[i] = ult[i+1];
		} else {
			ult[i] = i-1;
		}
	}

	ll res = 0, lim = 1LL * n * n;
	for (int i = 0; i < n; i++) {
		ll s = 0, p = 1;
		for (int j = i; j < n;) {
			if (A[j] == 1) {
				int k = ult[j];
				int tam = k-j+1;

				int k_ = p - s;
				if (k_ >= 1 and k_ <= tam) res++;
				j = ult[j] + 1;
				s += tam;
			} else {
				s += A[j];
				p *= A[j];
				if (p > lim) break;
				if (s == p) res++;
				j++;
			}
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

