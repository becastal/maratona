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
	setIO("cowdance");

	int n, t; cin >> n >> t;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	auto da = [&](int k) {
		map<int, int> s;
		for (int i = 0; i < k; i++) {
			s[a[i]]++;
		}

		for (int i = k; i < n; i++) {
			s[a[i] + s.begin()->f]++;
			if (--s[s.begin()->f] == 0) s.erase(s.begin()->f);
		}

		return s.rbegin()->f <= t;
	};

	int l = 1, r = n, res = n;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			res = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << res << endl;

    return(0);
}
