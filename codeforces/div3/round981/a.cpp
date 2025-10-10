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
	int n; cin >> n;

	int agr = 0, i = 1, mov = 1;
	while (1) {
		agr += (mov ? -1 : 1) * (2 * i  - 1);
		i++;
		if (abs(agr) > n) break;
		mov ^= 1;
	}
	cout << (mov ? "Sakurako" : "Kosuke") << endl;
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
