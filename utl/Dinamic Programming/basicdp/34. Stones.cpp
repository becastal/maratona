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

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	vector<int> dp(k + 1, 0);
	// dp[i]: se aquele que tem a vez ganha com a pilha em i;
	// 		  da pra afirmar que ele ganha se tu conseguir jogar o oponente pra uma posicao em que ele perde!

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - v[j] < 0) continue;
			if (!dp[i - v[j]]) 
				dp[i] = 1;
		}
	}

	cout << (dp[k] ? "First" : "Second") << endl;
    
    return(0);
}
