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
	ll x, y; cin >> x >> y;
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i, i *= -1;
	for (int& i : b) cin >> i, i *= -1;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ca = 0, cb = 0;
	ll sa = 0, sb = 0;
	for (int i = 0; i < n; i++) {
		sa += -a[i];
		ca++;
		if (sa > x) break;
	}

	for (int i = 0; i < n; i++) {
		sb += -b[i];
		cb++;
		if (sb > y) break;
	}

	cout << min(ca, cb) << endl;

    return(0);
}
