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

const int MAX = 1e5 + 10;

int main()
{
    _;

	int k; cin >> k;
	vector<int> s(k);
	for (int& i : s) cin >> i;

	// calculo dos grundy para cada heap possivel
	// nao eh um nim simples, entao o grundy number permite que eu reduza o jogo pra um nim que eu conheco.
	// dai eh so chamar no xor_sum que resolve. preciso entender a magica desse mex ainda.
	vector<int> grundy(MAX + 1, 0);
	for (int i = 1; i <= MAX; i++) {
		set<int> chega;
		for (int si : s) {
			if (i >= si) {
				chega.insert(grundy[i - si]);
			}
		}
		int mex = 0;
		while (chega.count(mex)) {
			mex++;
		}
		grundy[i] = mex;
	}

	int m; cin >> m;
	while (m--) {
		int l, res = 0; cin >> l;
		for (int i = 0, x; i < l; i++) {
			cin >> x; res ^= grundy[x];
		}
		cout << (res ? "W" : "L");
	}
	cout << endl;
    
    return(0);
}
