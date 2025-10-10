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
	vector<int> v(n);
	for (int& i : v) cin >> i;

	auto cont = [&](int x) {
		int res = 1;
		for (int i = 1; i < n; i++) {
			if (abs(v[i] - v[i-1]) > x) res++;
		}
		return res;
	};

	int l = 1, r = (int)1e7;
	while (l < r) {
		int mi = (l + r) / 2;

		if (cont(mi) > m) {
			l = mi + 1;
		} else {
			r = mi;
		}
	}

	cout << (cont(l) != m ? -1 : l) << endl;
    
    return(0);
}
