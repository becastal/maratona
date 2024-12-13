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

	ll n; cin >> n;
	cout << (1LL << (__builtin_popcountll(n))) << endl;
	//for (int n = 1; n <= 20; n++) {
	//	map<pair<int, int>, int> m;
	//	for (int i = 0; i < (1 << n); i++) {
	//		m[pair<int, int>(__builtin_popcount(i), n - __builtin_popcount(i))]++;
	//	}

	//	int res = 0;
	//	for (auto [i, cont] : m) {
	//		//cout << i.f << ' ' << i.s << ": " << cont << endl;
	//		res += cont & 1;
	//	}
	//	//printf("%2d: %d\n", n, res);
	//	//printf("%d, %d\n", res, (1 << __builtin_popcount(n)));
	//	cout << bitset<5>(n).to_string() << ' ' << res << endl;
	//}
    
    return(0);
}
