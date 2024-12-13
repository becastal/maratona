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
	string s; cin >> s;
	int cont = 0;

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') cont++;
		else if (s[i] == ')') {
			if (cont > 0) {
				res++, cont--;
			}
		}
	}
	cout << 2*res << endl;
    
    return(0);
}
