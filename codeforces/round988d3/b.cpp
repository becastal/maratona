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
	int k; cin >> k;
	// a*b==k-2;
	vector<int> v(k);
	map<int, int> freq;

	for (int& i : v) cin >> i, freq[i]++;
	for (int i = 0; i < k; i++) {
		freq[v[i]]--;
		
		if ((k-2)%v[i] == 0 and freq[(k-2) / v[i]]) {
			cout << v[i] << ' ' << (k-2) / v[i] << endl;
			return;
		}

		freq[v[i]]++;
	}
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
