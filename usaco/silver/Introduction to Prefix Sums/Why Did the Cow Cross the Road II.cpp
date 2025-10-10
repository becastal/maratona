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
	setIO("maxcross");

	int n, k, m; cin >> n >> k >> m;

	vector<int> v(n, 0);

	for (int i = 0, x; i < m; i++) {
		cin >> x; x--;
		v[x] = 1;
	}

	int agr = 0;
	for (int i = 0; i < k; i++) {
		agr += v[i];
	}

	int res = agr;
	for (int i = k; i < n; i++) {
		agr += v[i], agr -= v[i-k];
		res = min(res, agr);
	}
	cout << res << endl;

    return(0);
}
