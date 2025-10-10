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
typedef pair<double, double> ii;

int main()
{
    _;

	vector<ii> v(4);
	for (int i = 0; i < 4; i++) {
		cin >> v[i].f >> v[i].s;
	}

	auto ok = [](vector<ii> v) {
		double x1 = v[1].f - v[0].f;
		double y1 = v[1].s - v[0].s;
		double x2 = v[2].f - v[1].f;
		double y2 = v[2].s - v[1].s;
		return x1 * y2 - y1 * x2 > 0;		
	};

	int res = 1;
	for (int i = 0; i < 4 and ok; i++) {
		vector<pair<double, double>> agr;
		for (int j = 0; j < 4; j++) {
			if (j == i) continue;
			agr.push_back(v[j]);
		}
		res &= ok(agr);
	}

	cout << (res ? "Yes" : "No") << endl;
    
    return(0);
}
