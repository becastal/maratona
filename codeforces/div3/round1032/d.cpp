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
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	vector<pair<int, int>> res;

	for (int i = 1; i <= n; i++) {
		int pos = -1;
		for (int j = i-1; j < n and pos == -1; j++) {
			if (a[j] == i or b[j] == i) pos = j;
		}

		if (b[pos] == i) {
			res.emplace_back(3, pos + 1);
			swap(a[pos], b[pos]);
		}
		
		while (pos > i - 1) {
			res.emplace_back(1, pos);
			swap(a[pos], a[pos-1]);
			pos--;
		}

		pos = -1;
		for (int j = i-1; j < n and pos == -1; j++) {
			if (a[j] == n+i or b[j] == n+i) pos = j;
		}

		if (a[pos] == n+i) {
			res.emplace_back(3, pos + 1);
			swap(a[pos], b[pos]);
		}
		while (pos > i - 1) {
			res.emplace_back(2, pos);
			swap(b[pos], b[pos-1]);
			pos--;
		}
	}

	assert(is_sorted(a.begin(), a.end()));
	assert(is_sorted(b.begin(), b.end()));

	cout << (int)res.size() << endl;
	for (auto [i, j] : res) cout << i << ' ' << j << endl;

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
