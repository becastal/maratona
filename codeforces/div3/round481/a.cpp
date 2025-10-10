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
	map<int, int> f;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		f[x] = i;
	}

	vector<pair<int, int>> v;
	for (auto [a, b] : f) {
		v.emplace_back(b, a);
	}
	sort(v.begin(), v.end());
    
	cout << v.size() << endl;
	for (auto [a, b] : v) {
		cout << b << ' ';
	}
	cout << endl;

    return(0);
}
