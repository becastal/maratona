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
	ll p = 1;
	vector<int> res, ok(n, 0);
	for (int i = 1; i < n; i++) {
		if (gcd(i, n) == 1) {
			ok[i] = 1;
			p = p * i % n;
		}
	}
	if (p != 1) ok[p] = 0;

	cout << count(ok.begin(), ok.end(), 1) << endl;
	for (int i = 1; i < n; i++) {
		if (ok[i]) cout << i << ' ';
	}
	cout << endl;
    
    return(0);
}
