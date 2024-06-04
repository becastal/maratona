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
     
    int m, n;
     
    bool possivel(vector<tuple<int, int, int>>& a, int chute)
    {
    	int total = 0;	
     
    	for (auto [ti, yi, zi] : a)
    	{
    		int baloes = 0;
    		for (int i = 0; i < chute; i++)
    		{
    			if (baloes % zi == 0)
    				i += yi;
    			if (i % ti == 0)
    				baloes++;
    		}
    		total += baloes;
    	}
    	return (total >= m);
    }
     
    int main()
    {
        _;
     
    	cin >> m >> n;
     
    	vector<tuple<int, int, int>> a(n);
     
    	for (auto& [ti, yi, zi] : a)
    		cin >> ti >> yi >> zi;
     
    	int l = 0, r = 1.5e6 + 10;
     
    	while (l < r)
    	{
    		int mid = (l + r) / 2;
    	
    		if (possivel(a, mid))
    			r = mid;
    		else
    			l = mid + 1;
    	}
     
    	cout << l << endl;
    	for (auto [ti, yi, zi] : a)
    	{
    		int baloes = 0;
    		for (int i = 0; i < l; i++)
    		{
    			if (baloes % zi == 0)
    				i += yi;
    			if (i % ti == 0)
    				baloes++;
    		}
    		cout << baloes << " ";
    	}
    	cout << endl;
        
        return(0);
    }
