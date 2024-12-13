#include <bits/stdc++.h>
#include <atcoder/modint>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	mint::set_mod(m);

	mint a = 1, b = 0;
	cout << 0 << ' ';

	for (int i = 2; i <= n; i++) {
		mint c = (i - 1) * (a + b);
		cout << c.val() << ' ';
		a = b;
		b = c;
	}
	cout << endl;
}
