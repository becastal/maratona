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

void solve() {
	int n, k;
	cin >> n >> k;
	
	//vector<int> v(n, 0);
	//for (int i = 0; i < n and i+k-1 < n; i++) {
	//	v[i]++, v[i+k]--;
	//}

	//for (int i = 1; i < n; i++) {
	//	v[i] += v[i-1];
	//}
	//for (int i : v) cout << i << ' '; cout << endl;

	set<pair<int, int>> pq;
	vector<int> res(n, 0);
	
	for (int i = k-1; i < n; i += k) {
		res[i] = -1, pq.emplace(abs(i - (n-1)/2), i);
		if (i + k >= n) res[n-1] = -1, pq.emplace(abs((n-1) - (n-1)/2), n-1);
	}

	int x = 1;
	while (pq.size()) {
		res[pq.begin()->s] = x++;
		pq.erase(pq.begin());
	}

	//int x = 1, pos = (n-1)/2, dir = 0;
	//int l = pos - k, r = pos + k;

	//while (1) {
	//	if (pos < 0) {
	//		if (r < n) res[r] = x++;
	//		break;
	//	}
	//	if (pos >= n) break;

	//	if (pos >= 0 and pos < n) res[pos] = x++;
	//	if (dir) {
	//		r = pos + k;
	//		pos = l;
	//	} else {
	//		l = pos - k; 
	//		pos = r;
	//	}
	//	dir ^= 1;
	//}

	for (int& i : res) {
		if (!i) i = x++;
	}

	for (int i : res) cout << i << ' '; cout << endl;
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
