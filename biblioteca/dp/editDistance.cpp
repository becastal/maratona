#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define f first
#define s second

#define vi vector<int>
#define grafo vector<vector<int>>

#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 5*1e3+10;

int memo[MAX][MAX];

// Caixa preta de codigo para contar o numero
// minimo de movimentos para transformar uma
// string em outra. Complexity: O(M x N) , Space: O(M x N).

int dp(string s1, string s2){
	int n = s1.size(), m = s2.size();

	for(int i = 0; i <= n; i++) memo[i][0] = i;
	for(int j = 0; j <= m; j++) memo[0][j] = j;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(s1[i - 1] == s2[j - 1])// Verifica se os carac sao iguais
				memo[i][j] = memo[i - 1][j - 1];
			else
				memo[i][j] = 1 + min(memo[i - 1][j - 1], min(memo[i - 1][j], memo[i][j - 1]));
		}

	return memo[n][m];
}

int main(){ _
	string s1 , s2;cin>>s1>>s2;

	memset(memo, -1, sizeof memo);

	cout << dp(s1, s2) << endl;	
	return 0;
}

// CSES Edit Distance
