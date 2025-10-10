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

void solve() {
	int n, q; cin >> n >> q;

	vector<int> p(n), inv(n), diff(n, 0);
	for (int& i : p) cin >> i, i--;

	for (int i = 0; i < n; i++) {
		inv[p[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		int l = min(i, inv[i]);
		int r = max(i, inv[i]);
		diff[l]++; 
		if(r < n) diff[r]--;
	}
	for (int i = 1; i < n; i++) {
		diff[i] += diff[i - 1];
	}
	string s; cin >> s;

	int ruins = 0;
	vector<int> ruim(n-1, 0);
	auto f = [&](int i) {
		if (i < 0 or i >= n-1) return;
		if(ruim[i] and diff[i]) ruins--;
		ruim[i] = (s[i] == 'L' and s[i+1] == 'R');
		if(ruim[i] and diff[i]) ruins++;
	};

	for (int i = 0; i < n-1; i++) {
		ruim[i] = (s[i] == 'L' and s[i+1] == 'R');
		ruins += ruim[i] and diff[i];
	}

	while(q--) {
		int ii; cin >> ii; ii--;
		f(ii-1);
		f(ii);
		s[ii] = (s[ii] == 'L' ? 'R' : 'L');
		f(ii-1);
		f(ii);
		cout << (ruins ? "NO" : "YES") << endl;
	}
}

int main()
{
    _;
	setIO("");

	int t; cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
