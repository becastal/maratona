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

	int n, m, min_tam = INF; cin >> n >> m;
	for (int i = 0, l, r; i < m; i++) {
		cin >> l >> r;
		min_tam = min(min_tam, r - l + 1);
	}

	cout << min_tam << endl;
	for (int i = 0; i < n; i++) {
		cout << i % min_tam << " \n"[i==n-1];
	}
    
    return(0);
}
