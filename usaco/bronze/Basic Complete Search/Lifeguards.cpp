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
	setIO("lifeguards");

	int n; cin >> n;
	vector<pair<int, int>> a(n);
	vector<int> b(1010, 0);
	for (auto& [l, r] : a) {
		cin >> l >> r;
		for (int i = l; i < r; i++) {
			b[i]++;
		}
	}

	int res = 0;
	for (auto [l, r] : a) {
		for (int i = l; i < r; i++) {
			b[i]--;
		}

		int agr = 0;
		for (int i = 0; i <= 1000; i++) {
			agr += !!b[i];
		}
		res = max(res, agr);

		for (int i = l; i < r; i++) {
			b[i]++;
		}
	}

	cout << res << endl;

    return(0);
}
