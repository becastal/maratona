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
	setIO("helpcross");

	int c, n; cin >> c >> n;
	vector<int> T(c);
	vector<pair<int, int>> a(n);
	for (int& i : T) cin >> i;
	sort(T.begin(), T.end());

	for (auto& [l, r] : a) cin >> l >> r;
	sort(a.begin(), a.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	int pos = 0, res = 0;
	for (int t : T) {
		while (pos < n and a[pos].f <= t) {
			pq.emplace(a[pos++].s);
		}

		while (pq.size() and pq.top() < t) {
			pq.pop();
		}

		if (pq.size()) {
			pq.pop();
			res++;
		}
	}
	cout << res << endl;

    return(0);
}
