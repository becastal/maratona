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

	pair<int, int> a, b, c;
	cin >> a.f >> a.s;
	cin >> b.f >> b.s;
	cin >> c.f >> c.s;

	auto d = [] (pair<int, int> i, pair<int, int> j) {
		return (i.f - j.f) * (i.f - j.f) +  (i.s - j.s) * (i.s - j.s);
	};

	ll ab = d(a, b), ac = d(a, c), cb = d(c, b);
	ll hyp2 = max({ab, ac, cb});

	cout << (2 * hyp2 == ab + ac + cb ? "Yes" : "No") << endl;
    
    return 0;
}

