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

void solve_(int n, vector<int>& a) {
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);

	do {
		vector<int> a_;

		for (int i = 0, l = 0, r = n-1; i < n; i++) {
			if (p[l] < p[r]) {
				a_.insert(a_.begin(), p[l]);	
				l++;
			} else {
				a_.insert(a_.end(), p[r]);	
				r--;
			}
		}

		//for (int i : p) cout << i << ' '; cout << " -> ";
		//for (int i : a_) cout << i << ' '; cout << endl;
		auto a__ = a_;
		a__.insert(a__.begin(), a__.back());
		a__.pop_back();

		if (a_ == a or a__ == a) {
			for (int i : p) cout << i << ' '; cout << endl;
			return;
		}
	} while(next_permutation(p.begin(), p.end()));

	cout << -1 << endl;
}

int solve() {
	int n; cin >> n;

	vector<int> a(n);
	for (int& i : a) cin >> i;

	if (n <= 5) return solve_(n, a), 0;
	if (a.back() != n and a[0] != n) return cout << -1 << endl, 0;

	auto p = a;
	reverse(p.begin(), p.end());
	for (int i : p) cout << i << ' '; cout << endl;

	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
