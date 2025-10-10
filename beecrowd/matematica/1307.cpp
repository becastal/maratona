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

	int T; cin >> T;
	for (int t = 1; t <= T; t++ ){
		cout << "Pair #" << t << ": ";

		string a, b; cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		ll sa = 0, p2 = 1;
		for (int i = 0; i < (int)a.size(); i++) {
			sa += (a[i] == '1' ? p2 : 0LL);	
			p2 *= 2;
		}

		p2 = 1;
		ll sb = 0;
		for (int i = 0; i < (int)b.size(); i++) {
			sb += (b[i] == '1' ? p2 : 0LL);	
			p2 *= 2;
		}

		cout << (gcd(sa, sb) == 1 ? "Love is not all you need!" : "All you need is love!") << endl;
	}
    
    return(0);
}
