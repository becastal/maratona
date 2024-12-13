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
		int n; cin >> n;
		map<int, int> freq;
		for (int i = 0, x; i < n; i++) {
			cin >> x; freq[x]++;
		}
		int res = 0;
		for (auto [a, b] : freq) {
			res += b >> 1;
		}
		cout << res << endl;
	}
    
    return(0);
}
