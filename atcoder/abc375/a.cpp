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

	int n; cin >> n;
	string s; cin >> s;

	int res = 0;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == '#' and s[i+2] == '#' and s[i+1] == '.')
			res++;
	}
	cout << res << endl;
    
    return(0);
}
