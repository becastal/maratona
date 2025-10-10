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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	set<int> falta;
	for (int i = 0; i < (int)2e5+10; i++) {
		falta.emplace(i);
	}

	map<int, int> f;
	for (int i = 0; i < k; i++) {
		if (!f.count(a[i])) {
			falta.erase(a[i]);
		}
		f[a[i]]++;
	}

	cout << *falta.begin() << ' ';
	for (int i = k; i < n; i++) {
		if (--f[a[i-k]] == 0) {
			falta.insert(a[i-k]);
		}

		if (!f.count(a[i]) or f[a[i]] == 0) {
			falta.erase(a[i]);
		}
		f[a[i]]++;
		cout << *falta.begin() << ' ';
	}
	cout << endl;

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
