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

	string a, b; 
	while (cin >> a >> b and !(a == "0" and b == "0")) {
		int n = (int)a.size(), m = (int)b.size();	

		int res = 0, cr = 0, ai = n-1, bi = m-1;
		for (int i = 0; i < min(n, m); i++) {
			int ca = a[ai--] - '0', cb = b[bi--] - '0'; 

			if (ca + cb + cr > 9) {
				res++;
				cr = 1;
			} else {
				cr = 0;
			}
		}

		if (cr) {
			res += (n > m ? a[ai] - '0' + 1 > 9 : b[bi] - '0' + 1 > 9);
		}

		if (!res) {
			cout << "No carry operation." << endl;
		} else {
			cout << res << " carry operation" << (res == 1 ? "." : "s.") << endl;
		}
	}
    
    return(0);
}
