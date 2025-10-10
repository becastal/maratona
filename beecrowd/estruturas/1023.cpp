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
		if (cont) cout << endl;
		cout << "Cidade# " << ++cont << ':' << endl;
		map<double, double> v;

		double sx = 0, sy = 0;
		for (int i = 0; i < n; i++) {
			double x, y; cin >> x >> y;
			sx += x, sy += y;
			//v.emplace_back(floor(y/x), x);	
			v[floor(y/x)] += x;
		}

		int conti = (int)v.size();
		for (auto [a, b] : v) {
			cout << int(b) << '-' << int(a) << "\n "[!!(--conti)];
		}

		cout << fixed << setprecision(2);
		cout << "Consumo medio: " << floor(sy * 100.0 / sx) / 100.0 << " m3." << endl;
	}
    
    return(0);
}
