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
	vector<string> v(n);
	for (auto& s : v) cin >> s;
	int i, ok = 1;
	for (i = 1; i < n and ok; i++) {
		ok &= !(v[i] == v[i-1] and v[i] == "sweet");
	}
	cout << (i == n ? "Yes" : "No") << endl;
    
    return(0);
}
