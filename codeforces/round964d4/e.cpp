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
vector<int> pots;

void solve() {
	int l, r; cin >> l >> r;	

	vector<int> cont((int)pots.size(), 0);
	for (int i = 1; i < (int)pots.size(); i++) {
		if (l < pots[i] and r > pots[i - 1]) {
			int start = max(l, pots[i - 1]);
			int end = min(r, pots[i]);
			cont[i] = end - start;
		}
	}

	bool primeiro = 1;
	int res = 0;
	for (int i = 1; i < (int)cont.size(); i++) {
		if (cont[i] and primeiro) {
			if (cont[i] > 1) {
				cont[i]++;
			} else {
				cont[i + 1]++;	
			}
			primeiro = 0;
		}

		res += cont[i] * i;
	}
	cout << res << endl;
}

int main()
{
    _;
	int p = 1;
	while (p < 1e6) {
		pots.push_back(p);
		p *= 3;
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
