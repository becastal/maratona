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
	vector<int> p(n), q(n);
	for (int& i : p) cin >> i, i--;
	for (int& i : q) cin >> i, i--;

	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[q[i]] = q[p[i]];
	}

	for (int i : res) cout << i+1 << ' '; cout << endl;
    
    return(0);
}
