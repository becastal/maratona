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

	while (n--) {
		int J = 0, M = 0;
		for (int i = 0, x, d; i < 3; i++) {
			cin >> x >> d;
			J += x*d;
		}
		for (int i = 0, x, d; i < 3; i++) {
			cin >> x >> d;
			M += x*d;
		}

		cout << (J >= M ? "JOAO" : "MARIA") << endl;
	}
    
    return(0);
}
