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

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<char> cc = {'R', 'G', 'B'};
	vector<string> pad(3, "");

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < k; i++) {
			pad[j].push_back(cc[(i + j) % 3]);
		}
	}

	auto dif = [&](string& a, string& b) {
		int res = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			res += a[i] != b[i];
		}
		return res;
	};

	int res = INF;
	for (int i = 0; i <= n-k; i++) {
		string agr = s.substr(i, k);
		//dbg(agr);
		for (auto s : pad) {
			res = min(res, dif(agr, s));
		}
	}
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
