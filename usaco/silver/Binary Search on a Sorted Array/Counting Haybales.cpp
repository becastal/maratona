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
	setIO("haybales");

	int n, q; cin >> n >> q;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());

	while (q--) {
		int a, b; cin >> a >> b;

		int l = lower_bound(v.begin(), v.end(), a) - v.begin();
		int r = upper_bound(v.begin(), v.end(), b) - v.begin();
		cout << r - l << endl;
	}

    return(0);
}
