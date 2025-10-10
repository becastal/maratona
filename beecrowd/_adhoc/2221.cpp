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
		int bonus; cin >> bonus;
		int ai, bi, ci; cin >> ai >> bi >> ci;
		int aj, bj, cj; cin >> aj >> bj >> cj;
		
		int x = (ai + bi) / 2 + (ci&1^1)*bonus, y = (aj + bj) / 2 + (cj&1^1)*bonus;
		if (x == y) cout << "Empate" << endl;
		else cout << (x > y ? "Dabriel" : "Guarte") << endl;
	}
    
    return(0);
}
