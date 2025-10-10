#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);

	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	vector<int> v(m, 0);
	for (int i = 0; i < m; i++) {
		v[i] = a[i] <= b[i];	
	}
	if (count(v.begin(), v.end(), 1) >= m) return cout << 0 << endl, 0;
	for (int i = 1; i < m; i++) {
		v[i] += v[i-1];
	}

	vector<int> v_(m, 0);
	for (int i = 0; i < m-1; i++) {
		v_[i] = a[i+1] <= b[i];
	}
	for (int i = m-2; i >= 0; i--) {
		v_[i] += v_[i+1];
	}

	auto da = [&] (int k) {
		for (int i = 0; i < m; i++) {
			if (v[i] + (k >= b[i]) + v_[i] >= m) return 1;
		}
		return 0;
	};

	int l = 1, r = (int)1e9 + 10;
	while (l <= r) {
		int mm = l + (r - l) / 2;

		if (da(mm)) {
			r = mm-1;
		} else {
			l = mm+1;	
		}
	}

	if (l >= (int)1e9 + 10) return cout << -1 << endl, 0;
	cout << l << endl;

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
