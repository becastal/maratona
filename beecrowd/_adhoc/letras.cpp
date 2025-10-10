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

	char c; cin >> c;
	string p; 
	int bom = 0, tot = 0;
	while (cin >> p) {
		int ok = 0;
		for (int i = 0; i < (int)p.size() and !ok; i++) {
			ok |= (p[i] == c);
		}
		bom += ok;
		tot++;
	}

	cout << fixed << setprecision(1) << 100.0 * double(bom) / double(tot) << endl;
    
    return(0);
}
