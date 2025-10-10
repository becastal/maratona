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

	int a, b; cin >> a >> b;
	string s; cin >> s;
	int ok = 1;
	for (int i = 0; i < a + b and ok; i++) {
		if (i == a) continue;
		ok &= s[i] >= '0' and s[i] <= '9';
	}
	if (!b) ok = 0;
	else ok &= s[a] == '-';
	cout << (ok ? "Yes" : "No") << endl;
    
    return(0);
}
