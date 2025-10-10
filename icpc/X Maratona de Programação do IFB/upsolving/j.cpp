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

int solve() {
	double a, b, pi = acos(-1); cin >> a >> b;
	double a_ = sin(a * pi / 180.0), b_ = sin(b * pi / 180.0);

	if (a_ == b_) cout << "O Claudio ta do outro lado da roda!" << endl;
	else cout << (a_ < b_ ? "Olha o Claudio ali em cima!" : "O Claudio ta ali embaixo!") << endl;

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
