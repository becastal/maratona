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

	int q, cont = 0; cin >> q; cin.ignore(); cin.ignore();
	while (q--) {
		if (cont++) cout << endl;
		map<string, int> M;
		int tot = 0;
		string s;
		while (getline(cin, s)) {
			if (s == "") break;
			tot++;
			M[s]++;
		}

		for (auto [a, b] : M) {
			cout << a << fixed << setprecision(4) << ' ' << double(b) * 100.0 / tot << endl;
		}
	}
    
    return(0);
}
