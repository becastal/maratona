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
    
	map<string, string> M;
	int n; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		string s, t; getline(cin, s), getline(cin, t);
		M[s] = t;
	}

	int q; cin >> q; cin.ignore();
	for (int i = 0; i < q; i++) {
		string s, t; getline(cin, s), getline(cin, t);
		cout << s << endl << M[t] << endl << endl;
	}

    return(0);
}
