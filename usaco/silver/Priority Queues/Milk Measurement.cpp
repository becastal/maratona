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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("measurement");

	int n, g; cin >> n >> g;

	map<int, int> f, M;
	vector<tuple<int, int, int>> a(n);
	for (auto& [t, id, dx] : a) {
		cin >> t >> id >> dx;
		M[id] = g;
	}
	f[g] = n;

	int res = 0;
	sort(a.begin(), a.end());
	for (auto [t, id, dx] : a) {
		int l = M[id], era = l == f.rbegin()->first;
		int cont = f[l];

		f[l]--;
		if (f[l] == 0) f.erase(l);

		l += dx;
		M[id] = l;
		f[l]++;

		int eh = l == f.rbegin()->first;
		int cont_ = f[l];

		if (era) {
			if (eh and cont_ == cont) continue;
			res++;
		} else if (eh) {
			res++;
		}
	}
	cout << res << endl;

    return(0);
}
