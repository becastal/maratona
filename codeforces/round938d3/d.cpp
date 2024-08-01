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
		int n, m, k; cin >> n >> m >> k;
		vector<int> a(n);
		for (int& i : a) cin >> i;

		multiset<int> preciso, sim, sobra;
		for (int i = 0; i < m; i++) {
			int bi; cin >> bi;
			preciso.insert(bi);
		}

		for (int i = 0; i < m; i++) {
			if (preciso.find(a[i]) != preciso.end()) {
				preciso.erase(preciso.find(a[i]));
				sim.insert(a[i]);
			} else {
				sobra.insert(a[i]);	
			}
		}

		int res = (sim.size() >= k);
		for (int i = m; i < n; i++) { 
			int j = a[i - m];
			if (sobra.find(j) != sobra.end()) {
				sobra.erase(sobra.find(j));	
			} else if (sim.find(j) != sim.end()) {
				sim.erase(sim.find(j));
				preciso.insert(j);
			} 

			if (preciso.find(a[i]) != preciso.end()) {
				preciso.erase(preciso.find(a[i]));
				sim.insert(a[i]);
			} else {
				sobra.insert(a[i]);
			}

			res += (sim.size() >= k);
		}
		cout << res << endl;
	}
    
    return(0);
}
