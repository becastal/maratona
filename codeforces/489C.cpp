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

	int m, s; cin >> m >> s;
	vector<int> maior(m, 0), menor(m, 0);

	if (s == 0) return cout << (m == 1 ? "0 0" : "-1 -1") << endl, 0;
	if (s > m * 9) return cout << "-1 -1" << endl, 0;

	menor[0] = 1;
	int s1 = s - 1;
	for (int i = m-1; i >= 0 and s1; i--) {
		menor[i] = min(9, s1 + menor[i]);
		s1 -= menor[i];
	}

	int s2 = s;
	for (int i = 0; i < m and s2; i++) {
		maior[i] = min(9, s2);
		s2 -= maior[i];
	}

	for (int i : menor) cout << i;
	cout << ' ';
	for (int i : maior) cout << i;
	cout << endl;
    
    return(0);
}
