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
	setIO("swap");

	int n, k; cin >> n >> k;
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);

	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	a1--, a2--, b1--, b2--;

	set<vector<int>> vi = {v};
	for (int i = 1; ; i++) {
		reverse(v.begin() + a1, v.begin() + a2+1);
		reverse(v.begin() + b1, v.begin() + b2+1);

		if (vi.count(v)) break;
		vi.insert(v);
	}

	k %= vi.size();
	for (int i = 0 ; i < k; i++) {
		reverse(v.begin() + a1, v.begin() + a2+1);
		reverse(v.begin() + b1, v.begin() + b2+1);
	}

	for (int i : v) cout << i << endl;

    return(0);
}
