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
int n; 

int lis(vector<pair<int, int>>& v) {
	vector<int> l;
	
	l.push_back(INF);
	int res = 0;

	for (int i = 0; i < n; i++) {
		int agr = v[i].s;
		int idx = lower_bound(l.begin(), l.end(), agr+1)-l.begin();
		if (idx == l.size()-1) {
			res++;
			l.push_back(INF);
		}
		l[idx] = agr;
	}
	return res;
}

void solve() {
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].f >> v[i].s;
	}

	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
		if (a.f == b.f) return a.s < b.s;
		return a.f > b.f;
	});

	cout << lis(v) << endl;
}

int main() {
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

