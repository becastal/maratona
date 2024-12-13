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

	string s;
	while (getline(cin, s)) {
		stringstream ss(s);

		ll res = 0, agr = 0, n;
		while (ss >> n) {
			agr = max(0LL, agr + n);
			res = max(res, agr);
		}
		cout << res << endl;
	}
    
    return(0);
}
