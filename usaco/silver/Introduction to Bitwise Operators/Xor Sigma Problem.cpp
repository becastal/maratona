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
	setIO("");

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	ll res = -accumulate(v.begin(), v.end(), 0LL);
	for (int j = 0; j <= 30; j++) {
		vector<int> pre = {1, 0};

		int b = 0;
		for (int i : v) {
			b ^= !!(i & (1 << j));
			res += pre[b^1] * (1LL << j);
			pre[b]++;
		}
	}
	cout << res << endl;

    return(0);
}
