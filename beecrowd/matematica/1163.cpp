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

const double pi = 3.14159;
const double g = 9.80665;

int main()
{
    _;
	cout << fixed << setprecision(5);

	double h;
	while (cin >> h) {
		double p1, p2;
		cin >> p1 >> p2;

		int t; cin >> t;
		while (t--) {
			double alf, v;
			cin >> alf >> v;
			double ang = alf * pi / 180.0;
			double x = v * cos(ang) * ((v * sin(ang) + sqrt(v * sin(ang) * v * sin(ang) + 2 * g * h)) / g);
			
			cout << x << " -> " << (x >= p1 and x <= p2 ? "D" : "N") << "UCK" << endl;
		}
	}
    
    return(0);
}
