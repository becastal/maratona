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

	int n, t, p;
	cin >> n >> t >> p;

	int cont = 0;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	for (int i = 0; i < 1000; i++) {
		int cont = 0;
		for (int j = 0; j < n; j++) {
			cont += v[j] + i >= t;
		}
		if (cont >= p) return cout << i << endl, 0;
	}
	cout << -1 << endl;
    
    return(0);
}
