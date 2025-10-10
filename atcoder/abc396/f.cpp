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

template<typename T> ll inv_count(vector<T> l, vector<T> r = {}) {
	if (!r.size()) {
		r = l;
		sort(r.begin(), r.end());
	}
	int n = l.size();
	vector<int> v(n), bit(n);
	vector<pair<T, int>> w;
	for (int i = 0; i < n; i++) w.push_back({r[i], i+1});
	sort(w.begin(), w.end());
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(w.begin(), w.end(), make_pair(l[i], 0));
		if (it == w.end() or it->first != l[i]) return -1; // nao da
		v[i] = it->second;
		it->second = -1;
	}

	ll ans = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = v[i]-1; j; j -= j&-j) ans += bit[j];
		for (int j = v[i]; j < n; j += j&-j) bit[j]++;
	}
	return ans;
}

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	for (int i = 0; i < m; i++) {
		auto vi = v;
		for (int& j : vi) j = (j + i) % m;
		cout << inv_count(vi) << endl;
	}
    
    return(0);
}
