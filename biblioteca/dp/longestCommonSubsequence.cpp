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

//Implementacao de LCS de maneira recursiva
//retorna apenas o tamanho da maior subsequencia comum
//Complexity: O(NxM) | Space Complexity: O(NxM)
const int MAX = 1e3;
int memo[MAX][MAX];
int lcs(string& s1, string& s2, int i, int j){
	if(i<0 or j<0) return 0;

	int& pdm = memo[i][j];

	if(pdm != -1) return pdm;

	if(s1[i]==s2[j]){
		return pdm = lcs(s1, s2, i-1, j-1)+1;
	}

	return pdm = max(lcs(s1, s2, i-1, j), lcs(s1, s2, i, j-1));
}

//Implementando de maneira iterativa
// retorna apenas o tamanho da maior subsequencua comum
// caso deseja a maior sequencia palindroca
// inserir como parametros s1 e rev(s1)
// caso deseja o minimo de insercoes para tornar
// a string um palindromo basta
// size(s1) - lcs(s1,rev(s1)
// Complexity: O(NxM) | Space Complexity: O(N+M)
int lcs(string& s1, string& s2){
	int n = s1.size();
	int m = s2.size();

	vector<int> prev(m+1, 0), cur(m+1, 0);

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(s1[i-1]==s2[j-1])
				cur[j]=prev[j-1]+1;
			else
				cur[j]=max(prev[j], cur[j-1]);
		}
		prev=cur;
	}
	return prev[m];
}

// Funcao para imprimir a maior subsequencia comum
// Complexity: O((NxM)+(N+M)) | Space Complexity: O(NxM)
string imprimirLCS(string& s1, string& s2){
	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int len = dp[n][m];
	string ans = "";
	
	for(int i = 0; i < len; i++)ans+='$';

	int idx = len-1;
	int i = n, j = m;

	while(i>0 and j>0){
		if(s1[i-1]==s2[j-1]){
			ans[idx]=s1[i-1];
			idx--;i--;j--;
		}
		else if (dp[i-1][j]>dp[i][j-1]){
			i--;	
		}
		else{
			j--;
		}
	}
	return ans;
}
int main(){ _
	
	string s1 = "abcde";
	string s2 = "cde";

	int n = s1.size()-1;
	int m = s2.size()-1;

	memset(memo, -1, sizeof memo);

	cout << lcs(s1, s2) << endl;
	cout << imprimirLCS(s1, s2) << endl;
	return 0;
}
