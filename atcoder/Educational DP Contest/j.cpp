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

const int MAX = 305;
double dp[MAX][MAX][MAX];

int main()
{
    _;

	int n; cin >> n;
	vector<int> cont(4);
	for (int i = 0; i < n; i++) {
		int vi; cin >> vi;
		cont[vi]++;
	}

	// o minimo de operacoes eh trivial: a soma de todos os vi.
	// mas, durante o processo, algumas operacoes vao ser inuteis por terem caido em um vi que ja era 0.
	
	// importante guardar, a cada nova operacao:
	//   - a quantidade de operacoes que ja foram;
	//   - a quantidade cada um dos valores que a array apresenta (3, 2, 1).
	// ... dp[i][j][k]: quantidade de operacoes esperadas para se ter i 1s, j 2s e k 3s.

	for () {
		for () {
			for () {
				
			}
		}
	}
    
    return(0);
}
