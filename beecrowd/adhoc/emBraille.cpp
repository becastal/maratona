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
    
	vector<vector<string>> m = {
		{".*", "**", ".."},
		{"*.", "..", ".."},
		{"*.", "*.", ".."},
		{"**", "..", ".."},
		{"**", ".*", ".."},
		{"*.", ".*", ".."},
		{"**", "*.", ".."},
		{"**", "**", ".."},
		{"*.", "**", ".."},
		{".*", "*.", ".."}
	};
	
	map<vector<string>, char> mp = {
		{{".*", "**", ".."}, '0'},
		{{"*.", "..", ".."}, '1'},
		{{"*.", "*.", ".."}, '2'},
		{{"**", "..", ".."}, '3'},
		{{"**", ".*", ".."}, '4'},
		{{"*.", ".*", ".."}, '5'},
		{{"**", "*.", ".."}, '6'},
		{{"**", "**", ".."}, '7'},
		{{"*.", "**", ".."}, '8'},
		{{".*", "*.", ".."}, '9'}
	};

	int d;
	while (cin >> d and d)
	{
		char com; cin >> com;
		if (com == 'S')
		{
			string s; cin >> s;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < s.size(); j++)
					cout << m[s[j] - '0'][i] << (j < s.size() - 1 ? " " : ""); 
				cout << endl;
			}
		}
		else if (com == 'B')
		{
			vector<vector<string>> q(d);	
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < d; j++)
				{
					string s; cin >> s;
					q[j].push_back(s);
				}

			for (auto qi : q)
				cout << mp[qi];
			cout << endl;
		}
	}


    return(0);
}
