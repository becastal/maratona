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
	vector<tuple<int, int, int, string>> v(n);
	for (int i = 0; i < n; i++)
	{
		auto& [o, p, b, nome] = v[i];
		cin >> nome >> o >> p >> b;
		o = -o, p = -p, b = -b;
	}
	sort(v.begin(), v.end());
   	for (auto& [o, p, b, nome] : v)
		cout << nome << ' ' << -o << ' ' << -p << ' ' << -b << endl;

    return(0);
}
