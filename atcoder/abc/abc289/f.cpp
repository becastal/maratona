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
typedef pair<pair<int, int>, pair<int, int>> ii;

const int maxn = 1e6;

int main()
{
    _;

	ll sx, sy;
	cin >> sx >> sy;

	ll tx, ty;
	cin >> tx >> ty;

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ii agr;
	agr.f.f = agr.s.f = tx;
	agr.f.s = agr.s.s = ty;

	vector<pair<int, int>> res;
	int ok = 0;
	for (int i = 0; i < maxn and !ok; i++) {
		res.emplace_back((agr.f.f + agr.s.f) / 2, (agr.f.s + agr.s.s) / 2);

		// aqui mais facil ver todos os pontos que da do meu quad pro quado do meio.
		ii agri;
		agri.f.f = 2*a-agr.f.f;
		agri.f.s = 2*c-agr.f.s;
		agri.s.f = 2*b-agr.s.f;
		agri.s.s = 2*d-agr.s.s;

		ok |= sx >= agri.f.f and sx <= agri.s.f and sy >= agri.f.s and sy <= agri.s.s;
		agr = agri;
	}

	if (!ok) return cout << "No" << endl, 0;

	res.emplace_back(sx, sy);
	reverse(res.begin(), res.end());
	cout << "Yes" << endl;
   	for (auto [xi, yi] : res) cout << xi << ' ' << yi << endl; 

    return(0);
}
