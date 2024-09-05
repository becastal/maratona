/* 
forest queries

explicacao:
	prefix sum em 2d. quer saber quantas arvores
	no retangulo definido dentro da array;
*/

int main()
{
    _;

	int n, q; cin >> n >> q;
	vector<vector<int>>  mp(n, vector<int> (n)), pre(n + 1, vector<int>(n + 1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			char c; cin >> c;
			mp[i][j] = (c == '*');
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pre[i][j] = mp[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
	
	while (q--)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << pre[y2][x2] - pre[y2][x1 - 1] - pre[y1 - 1][x2] + pre[y1 - 1][x1 - 1] << endl;
	}
    
    return(0);
}
