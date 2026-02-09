#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, k, x; cin >> n >> k >> x;
	vector<string> V(n), R;
	for (auto& i : V) cin >> i;

	vector<int> A;
	function<void(int)> f = [&](int pos) {
		if (pos == k) {
			string s = "";
			for (int i : A) {
				s += V[i];
			}
			R.push_back(s);
			return;
		}

		for (int i = 0; i < n; i++) {
			A.push_back(i);
			f(pos + 1);
			A.pop_back();
		}
	};
	f(0);

	sort(all(R));
	cout << R[x-1] << endl;

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
