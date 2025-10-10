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

	ll res_ = -LINF, pos_;
	for (int i = 0; i < n; i++) {
		vector<int> A(n);
		for (int& i : A) cin >> i;


		ll res = -LINF, pos = 0;
		ll pref = 0, suf = -accumulate(all(A), 0LL);
		for (int j = 0; j < n; j++) {
			suf += A[j];
			ll agr = (n - j - 1) * pref + suf;

			if (res < agr) {
				res = agr;
				pos = j;
			}

			pref += A[j];
		}

		if (res_ < res) {
			res_ = res;
			pos_ = i;
		}
		cout << pos + 1 << " \n"[i==n-1];
	}
	cout << pos_ + 1 << ' ' << res_ << endl;

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
