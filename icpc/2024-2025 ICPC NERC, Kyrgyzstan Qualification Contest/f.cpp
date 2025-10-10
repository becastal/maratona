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
	vector<ll> a(n);
	for (ll& i : a) cin >> i;

	ll t = 0;
	for (int i = 0; i < n; i++) {
		t += a[i];

		ll ri, gi, di; 
		cin >> ri >> gi >> di; 
		
		ll l = 0, r = (ll)1e10+10;

		while (l < r) {
			int j = (l + r) / 2;
			if (t <= -di + (ri + gi) * j  or (t >= -di + (ri + gi) * j and t < -di + (ri + gi) * j + gi)) {
				r = j;
			} else {
				l = j + 1;
			}
		}

		if (t < -di + (ri + gi) * l) {
			t = -di + (ri + gi) * l;
		}
	}
	cout << t << endl;
    
    return(0);
}
