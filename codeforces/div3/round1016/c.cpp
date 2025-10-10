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

int primo(int n) {
	if (n == 1) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		cout << (k == 1 and primo(n) or (n == 1 and k == 2) ? "YES" : "NO") << endl;
	}
    
    return(0);
}
