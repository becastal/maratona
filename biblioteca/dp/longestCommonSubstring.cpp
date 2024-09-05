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

int lcs(string& s1, string& s2){
	int n = s1.size();
	int m = s2.size();

	vector<int> prev(m+1, 0), cur(m+1, 0);
	int ans = -INF;

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(s1[i-1]==s2[j-1]){
				cur[j]=prev[j-1]+1;
				ans = max(ans, cur[j]);
			}
			else cur[j]=0;
		}
		prev=cur;
	}

	return ans;
}

int main(){ _
	string s1 = "abcde";
	string s2 = "abde";

	cout << lcs(s1, s2) << endl;
	return 0;
}
