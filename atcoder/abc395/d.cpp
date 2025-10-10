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

    int n, q; 
    cin >> n >> q;
    vector<int> pos(n+1), nom(n+1), cont(n+1);
    iota(pos.begin(), pos.end(), 0);
    iota(nom.begin(), nom.end(), 0);
    iota(cont.begin(), cont.end(), 0);

    while (q--) {
        int tp; 
        cin >> tp;

        if (tp == 1) { 
            int a, b; cin >> a >> b;

			pos[a] = nom[b];
        } else if (tp == 2) {
            int a, b; cin >> a >> b;
            
			swap(nom[a], nom[b]);
			int x = nom[a], y = nom[b];
			cont[x] = a;
			cont[y] = b;
        } else if (tp == 3) {
            int a; cin >> a;
            cout << cont[pos[a]] << endl;
        }
    }
    
    return(0);
}

