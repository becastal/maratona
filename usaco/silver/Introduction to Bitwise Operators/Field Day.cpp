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

	int c, n; cin >> c >> n;
	vector<int> v(n), d(1 << c, -1);
	queue<int> q;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == 'G') v[i] |= (1 << j);
		}
		
		d[v[i]] = 0;
		q.push(v[i]);
	}

	while (q.size()) {
		int u = q.front(); q.pop();

		for (int i = 0; i < c; i++) {
			if (d[u ^ (1 << i)] != -1) continue;
			d[u ^ (1 << i)] = d[u] + 1;
			q.push(u ^ (1 << i));
		}
	}

	auto inv = [&c](int x) {
		int res = 0;
		for (int i = 0; i < c; i++) {
			if (x & (1 << i)) continue;
			res |= 1 << i;
		}
		return res;
	};
	for (int i : v) {
		cout << c - d[inv(i)] << endl;
	}

    return(0);
}
