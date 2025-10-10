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

int solve() {
	int n, k; cin >> n >> k;

	int id_ = 0;
	vector<int> cont(210, 0), usei(n, 0), res;
	vector<tuple<int, int, int>> v(n);
	for (auto& [a, b, id] : v) {
		id = id_++;
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			cont[i]++;
		}
	}


	for (int i = 1; i < 210; i++) {
		while (cont[i] > k) {
			int a_ = -1, b_ = -1, idd, pos, jj = 0;

			for (auto& [a, b, id] : v) {
				if (!usei[id] and i >= a and i <= b and b > b_) {
					a_ = a;	
					b_ = b;	
					idd = id;
				}
			}

			res.push_back(idd);
			usei[idd] = 1;
			for (int j = a_; j <= b_; j++) {
				cont[j]--;	
			}
		}
	}

	cout << res.size() << endl;
	for (int i : res) cout << i+1 << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
