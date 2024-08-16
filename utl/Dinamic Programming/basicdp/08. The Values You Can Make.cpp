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
// acho que sei resolver mas ta chato pra debugar.
// eh tipo o minimizing coins, mas tu nao pode pegar duas vezes a mesma moeda.
// o n eh 500 entao minha solucao cubica acho que passa:
//    marca um jeito que tu chegou em cada valor com um vector<int>, sendo 1 se o valor ja foi usado ou nao
//    dai pra cada i da dp, tu olha cada vetor de jeito de chegar la e calcula pra todos os outros jeitos.
//    no fim, ve quantos i_s tu conseguiu chegar e responde. nada demais.

int main()
{
    _;

    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    vector<vector<vector<int>>> dp(k + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] <= k) {
			vector<int> vi(n, 0);
			vi[i] = 1;	
			dp[v[i]].push_back(vi);	
		}
	}

	//for (int i = 0; i <= k; i++) {
	//	cout << setw(3) <<  i << ' ' << dp[i].size() << endl;
	//}

	for (int i = 0; i <= k; i++) {
		for (auto vi : dp[i]) {
			for (int j = 0; j < n; j++) {
				if (vi[j] or i + v[j] > k) continue;
				auto vii = vi;
				vii[j] = 1;
				dp[i + v[j]].push_back(vii);
			}
		}
	}

	vector<int> res = {0};
	for (int i = 0; i <= k; i++) {
		if (dp[i].size()) {
			res.push_back(i);
		}
	}

	cout << res.size() << endl;
	for (int i : res)
		cout << i << ' ';
	cout << endl;
    
    return 0;
}

