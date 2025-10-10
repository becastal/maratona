#include <bits/stdc++.h>
#define f first
#define s secont
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main() {

	int n; cin >> n;
	vector<int> v(n);
	map<int, int> f;
	for (int& i : v) cin >> i, f[i]++;

	int res = 0;
	for (auto [a, b] : f) {
		res = max(res, b);
	}
	cout << res << endl;

	return 0;
}
