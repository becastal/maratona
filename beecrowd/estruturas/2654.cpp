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

	for (auto& [a, b, c, nome] : v) {
		cin >> nome >> a >> b >> c;
		a = -a, b = -b;
	}

	sort(v.begin(), v.end());
	cout << get<3>(v[0]) << endl;
    
    return(0);
}
