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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<double> v(n);

		double tot = 0;
		for (auto& i : v) cin >> i, tot += i;

		double med = tot / n, cont = 0;
		for (auto& i : v) {
			if (i > med) cont += 1;	
		}

		cout << fixed << setprecision(3) << cont / n * 100.0 << "%" << endl;
	}
    
    return(0);
}
