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
typedef pair<int, int> ii;

double dist (const ii& a, const ii& b) {
	return sqrt((a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));
}

int main()
{
    _;

	int n, k; cin >> n >> k;

	vector<ii> cid(n);
	vector<ii> cap(k);
	for (auto& [i, j] : cid) cin >> i >> j;
	for (auto& [i, j] : cap) cin >> i >> j;

	vector<tuple<double, int, int>> ar;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			arr.emplace_back(dist(cid[i], cap[i]), i, j);
		}
	}

	double res = 0.0;
	sort(ar.begin(), ar.end());
	for (auto [w, a, b] : ar) {
		if (dsu.find(a) != dsu.find(b)) {
			res += w;
			dsu.merge(a, b);
		}
	}

	// agora eh so kruskal;
    
    return(0);
}
