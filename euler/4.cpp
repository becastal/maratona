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

	int res = 0;
	auto pal = [](int x) {
		string S = to_string(x);
		for (int l = 0, r = (int)S.size()-1; l < r; l++, r--) {
			if (S[l] != S[r]) return 0;
		}
		return 1;
	};
	for (int i = 100; i < 1000; i++) {
		for (int j = i + 1; j < 1000; j++) {
			if (pal(i * j)) res = max(res, i * j);
		}
	}
	cout << res << endl;

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
