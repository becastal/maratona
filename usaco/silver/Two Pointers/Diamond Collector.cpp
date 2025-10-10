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
	setIO("diamond");

	int n, k; cin >> n >> k;
	vector<int> v(n), tam(n), suf(n+1, 0);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());

	for (int l = 0, r = 0; l < n; l++) {
		while (r < n and v[r] - v[l] <= k) {
			r++;
		}

		tam[l] = r - l;
	}

	for (int i = n-1; i >= 0; i--) {
		suf[i] = max(suf[i+1], tam[i]);
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, tam[i] + suf[i + tam[i]]);
	}
	cout << res << endl;

    return(0);
}
