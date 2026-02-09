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

	string s, t;
	cin >> s >> t;

	int achou = 0;
	for (int i = 0; i < min((int)s.size(), (int)t.size()) and !achou; i++) {
		achou = (s[i] != t[i]) * (i + 1);
	}

	if (achou) return cout << achou << endl, 0;
	if ((int)s.size() != (int)t.size()) return cout << min((int)s.size(), (int)t.size()) + 1 << endl, 0;
	cout << 0 << endl;

    return(0);
}
