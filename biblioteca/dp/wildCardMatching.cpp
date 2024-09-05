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


bool ans(string& pattern, string& text){

	int n = pattern.size(), m = text.size();

	vector<bool> prev(m+1, false), cur(m+1, false);
	prev[0]=true;

	for(int j = 1; j<=m; j++)
	prev[j] = false;

	for(int i = 1; i<=n; i++){

		bool flag = false;
		for(int ii = 1; ii<=i; ii++){
			if(pattern[ii-1]!='*'){
				flag=true;
				break;
			}
		}
		prev[0]=flag;

		for(int j = 1; j<=m; j++){
			if(pattern[i-1]==text[j-1] or pattern[i-1]=='?')
				cur[j]=prev[j-1];
			else if(pattern[i-1]=='*')
				cur[j]=prev[j] or cur[j-1];
			else cur[j]=false;
		}
		prev=cur;
	}
	return prev[m];
}

int main(){ _
	string pattern = "ab*cd";
	string text = "abcdefcd";
	

	cout << (ans(pattern,text) ? "foi" : "n foi :(") << endl;
	return 0;
}
