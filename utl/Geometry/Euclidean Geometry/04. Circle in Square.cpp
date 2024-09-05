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
typedef double ld;
const ld pi = 2.0*acos(0.0);

int main()
{
    _;

	int t; cin >> t;
	for (int T = 1; T <= t; T++) {
		ld r; cin >> r;
		cout << fixed << setprecision(2) << "Case: " << T << ": " << (4.0 - pi) * r * r << endl;
	}
    
    return(0);
}
