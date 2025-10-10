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

int main()
{
    _;
    
	int t; cin >> t;
	while (t--) {
		vector<set<string>> v(3);
		vector<vector<string>> vs(3);
		vector<int> res(3, 0);
		int n; cin >> n;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				string s; cin >> s;
				v[i].emplace(s);
				vs[i].push_back(s);
			}
		}

		for (int i = 0; i < 3; i++) {
			for (auto s : vs[i]) {
				int agr = 0;
				for (int j = 0; j < 3; j++) {
					agr += v[j].count(s);
				}

				if (agr == 2) res[i] += 1;
				if (agr == 1) res[i] += 3;
			}
		}

		for (int i : res) cout << i << ' '; cout << endl;
	}

    return(0);
}
