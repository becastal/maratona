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

	int n, cont = 0;
	while (cin >> n and n) {
		if (cont++) cout << endl;
		vector<string> v(n);
		int mx = 0;
		for (auto& s : v) cin >> s, mx = max(mx, (int)s.size());

		for (auto& s : v) cout << setw(mx) << s << endl;
	}
    
    return(0);
}
