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

// Funcao para encontrar a qtd de substring iguais a B em A
// Time Complexity: O(NxM) | Space: O(M);
int dp(string& s1, string& s2){
	int n = s1.size();
	int m = s2.size();
	
	vector<int> prev(m+1, 0);

	prev[0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			if(s1[i-1]==s2[j-1])
				prev[j] = prev[j-1] + prev[j];
		}
	}

	return prev[m];
}

int main(){ _
	string s1 = "brootgroot";
	string s2 = "brt";

	cout << dp(s1, s2) << endl;
	return 0;
}
