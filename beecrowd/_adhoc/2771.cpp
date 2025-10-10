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

void solve(int n, int k) {
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<double> res;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				res.push_back((1.0 * v[i] + 1.0 * v[j] + 1.0 * v[k]) / 3.0);
			}
		}
	}

	sort(res.rbegin(), res.rend());
	cout << fixed << setprecision(1) << res[k-1] << endl;
}

int main()
{
    _;

	int n, k; 
	while (cin >> n >> k) {
		solve(n, k);
	}
    
    return(0);
}
