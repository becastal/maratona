#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
max(i, j, k) = j ou seja:
	- 7 3 5
	- 3 7 5

min(i, j, k) = j ou seja:
	- 5 3 7
	- 5 7 3

isso aqui resolve pra gcd == 1;

*/

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	auto f = [&](int a, int b, int c) {
		ll res = 0;
		map<int, int> Ca, Cc;
		if (A[0] % a == 0) {
			Ca[A[0] / a]++;
		}
		for (int i : A) if (i % c == 0) {
			Cc[i / c]++;
		}

		for (int i = 1; i < n - 1; i++) {
			if (A[i] % a == 0) {
				Ca[A[i] / a]++;
			}
			if (A[i] % c == 0) {
				Cc[A[i] / c]--;
			}
			if (A[i] % b == 0) {
				int q = A[i] / b;
				res += 1LL * Ca[q] * Cc[q];
			}
		}

		return res;
	};

	auto g = [&](int a, int b, int c) {
		ll res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					int a_ = A[i], b_ = A[j], c_ = A[k];
					int gc = gcd(a_, gcd(b_, c_));
					if (a_ / gc == a and b_ / gc == b and c_ / gc == c) {
						res++;
					}
				}
			}
		}
		return res;
	};

	ll res = 0;
	res += f(7, 3, 5);
	res += f(3, 7, 5);
	res += f(5, 3, 7);
	res += f(5, 7, 3);
	cout << "f(7, 3, 5): " << f(7, 3, 5) << ", " << g(7, 3, 5) << endl;
	cout << "f(3, 7, 5): " << f(3, 7, 5) << ", " << g(3, 7, 5) << endl;
	cout << "f(5, 3, 7): " << f(5, 3, 7) << ", " << g(5, 3, 7) << endl;
	cout << "f(5, 7, 3): " << f(5, 7, 3) << ", " << g(5, 7, 3) << endl;
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

