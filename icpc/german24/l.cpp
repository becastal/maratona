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

    string s; cin >> s;
    int n = (int)s.size();

    int agr = 0;
    for (int i = 0; i < n; i++) {
        agr += (s[i] == '(' ? 1 : -1);
        if (agr != 0) continue;
        
        string si = s.substr(i+1, n-(i+1)) + s.substr(0, i+1);
        if (s != si) {
			return cout << si << endl, 0;
		} else {
			return cout << "no" << endl, 0;
		}
    }
    
    return 0;
}

