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
    int n = s.size(), i = 0, j = 0, res = 0;
	
    while (i < n) {
        if (s[i] == (j % 2 == 0 ? 'i' : 'o')) {
            i++;
            j++;
        } else{
            res++;
            j++;
        }
    }

    if (j & 1) {
        res++;
    }
    cout << res << endl;

    return(0);
}

