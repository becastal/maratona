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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("promote");

	int bb, ba, sb, sa, gb, ga, pb, pa, ts, tg, tp;
    cin >> bb >> ba >> sb >> sa >> gb >> ga >> pb >> pa;

    tp = pa - pb;
    tg = ga - gb + pa - pb;
    ts = sa - sb + ga - gb + pa - pb;

    cout << ts << endl << tg << endl << tp << endl;

    return(0);
}
