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
	vector<int> a(n);
	for (int& i : a) cin >> i;

	int res = 0;
	for (int i = 0; i < n; i++) {
		int agr = 0;
		for (int j = 0; j < n; j++) {
			agr += a[j] >= a[i] and a[j] <= a[i] + k;
		}
		res = max(res, agr);
	}
	cout << res << endl;

    return(0);
}
