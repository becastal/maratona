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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> res;

	function<int(int, vector<int>)> f = [&] (int i, vector<int> v) {
		if (v.back() > m) return 0;

		if (i == n) {
			res.push_back(v);
			return 1;
		}

		int j = v.back()+10, ok = v.back() + (n-i) * 10 <= m;
		while (ok) {
			auto vi = v; vi.push_back(j);
			ok &= f(i+1, vi);
			j++;
		}
		return 1;
	};

	for (int i = 1; i < 20; i++) {
		f(1, {i});
	}

	cout << res.size() << endl;
	for (auto v : res) {
		for (int i : v) {
			cout << i << ' ';
		}
		cout << endl;
	}
    
    return(0);
}
