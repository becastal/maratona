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
	int n; cin >> n;
	string s; cin >> s;

	vector<int> P, A;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') P.push_back(i);	
		if (s[i] == '*') A.push_back(i);	
	}

	auto da = [&](int m) {
		int i = 0;
		for (int p : P) {
			if (i >= A.size()) break;

			int l = A[i], r = 0;
			if (abs(p - l) > m) continue;
				
			if (p <= l) {
				r = p + m;
			} else {
				int d = abs(p - l);	
				r = p + max(m - 2 * d, (m - d) / 2);
			}

			while (i < (int)A.size() and A[i] <= r) i++;
		}
		return i == (int)A.size();
	};

	int l = 0, r = 2*n, res = 2*n;
	while (l <= r) {
		int m = l + (r - l) / 2;


		if (da(m)) {
			res = m;
			r = m - 1;
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

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
