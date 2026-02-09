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

	int n; cin >> n;
	
	vector<unordered_map<int, int>> fre(n);
	vector<unordered_map<int, double>> v(n);

	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		for (int j = 0, x; j < m; j++) {
			cin >> x;
			fre[i][x]++;
		}

		for (auto& [x, p] : fre[i]) {
			v[i][x] = double(p) / double(m);
		}
	}

	double res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			double agr = 0;
			for (auto [x, p] : v[i]) {
				if (v[j].count(x)) agr += p * v[j][x];
			}

			res = max(res, agr);
		}
	}
	cout << fixed << setprecision(12) << res << endl;
    
    return(0);
}
