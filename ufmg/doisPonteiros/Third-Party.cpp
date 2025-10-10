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

	int n, m, ii = 1; cin >> n >> m;
	vector<tuple<int, int, int>> v(n);
	for (auto& [a, b, i] : v) cin >> a >> b, i = ii++;

	sort(v.begin(), v.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) {
		auto [la, ra, ia] = a;
		auto [lb, rb, ib] = b;

		if (la == lb) return ra > rb;
		return la < lb;
	});

	vector<int> res;
    int r = 1, l = 0;
    while (r <= m) {
        int nr = -1, ni = -1;

        while (l < n and get<0>(v[l]) <= r) {
            if (get<1>(v[l]) > nr) {
                nr = get<1>(v[l]);
                ni = get<2>(v[l]);
            }
            l++;
        }

        if (ni == -1) {
            cout << "NO" << endl;
            return 0;
        }
        res.push_back(ni);
        r = nr + 1;
    }

    cout << "YES" << endl << res.size() << endl;
    for (int i : res) cout << i << ' '; cout << endl; 

    return(0);
}
