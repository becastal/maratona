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
typedef double ld;

void solve() {
	ld ab, ac, bc, raz;
	cin >> ab >> ac >> bc >> raz;

	ld l = 0, r = ab, ad;
	auto razao = [&]() {
		ld ae = (ad * ac) / ab, de = (ad * bc) / ab;
		
		ld s1 = (ab+ac+bc)/2.0, s2 = (ad+ae+de)/2.0;
		ld peq = sqrt(s1 * (s1 - ab) * (s1 - ac) * (s1 - bc));
		ld gra = sqrt(s2 * (s2 - ad ) * (s2 - ae) * (s2 - de));
		ld trapezio = gra - peq;

		return peq / trapezio;
	};
		
	for (int i = 0; i < (int)1e2; i++) {
		ad = (l+r)/2.0;

		if (razao() > raz) {
			l = ad;
		} else {
			r = ad;
		}
	}

	cout << fixed << setprecision(10);
	cout << ad << endl;
}

int main()
{
    _;

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
    
    return(0);
}
