#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int bruto() {
	int n; cin >> n;
	int an; cin >> an;

	vector<int> A = {an};
	set<int> S;

	function<void(int)> f = [&](int p) {
		if (p == n-1) {
			int res = 0;
			for (int i = 1; i < n; i++) {
				res += A[i-1] % A[i];
			}
			//for (int i : A) cout << i << ' '; cout << ": " << res << endl;
			S.insert(res);
			return;
		}
		
		int t = A.back();
		for (int i = 1; i <= t; i++) {
			A.push_back(i);
			f(p + 1);
			A.pop_back();
		}
	};
	f(0);
	cout << "(";
	for (int i : S) cout << i << ' ';
	cout << ")" << endl;


	return(0);
}

int solve() {
	int n, k; cin >> n >> k;
	ll l = 1, r = 1e12, An = r;

	auto da = [&](ll m) {
		ll res = 0, ult = m;
		for (int i = 0; i < n-1 and ult != 1; i++) {
			res += (ult - 1) / 2;
			ult = ult / 2 + 1;	
		}
		return res >= k;	
	};

	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) { 
			r = m-1;	
			An = m;
		} else {
			l = m+1;
		}
	}

	vector<ll> A = {An};
	for (int i = 0; i < n-1 and k; i++) {
		int mx = (A.back() - 1) / 2;

		if (k >= mx) {
			int Ai = A.back() / 2 + 1;
			A.push_back(Ai);
			k -= mx;
		} else {
			// tem que matar agroa
			int Ai = A.back() - k;
			A.push_back(Ai);
			k = 0;
		}
	}

	while (A.size() < n) A.push_back(1);

	reverse(all(A));
	for (int i : A) {
		cout << i << ' ';
	}
	cout << endl;

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

