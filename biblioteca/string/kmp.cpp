/* 
	kmp

	descricao:
		retorna todas as posicoes em que s ocorre em t;
		da pra fazer com memoria o(n) se ler t cada char por vez

	complexidade:
		memoria: o(|n| + |m|)
		acha: o(|n| + |m|
*/

// [...] pi;
vector<int> pi(string& s) {
    int n = (int) s.size();
    vector<int> p(n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j and s[i] != s[j]) 
            j = p[j - 1];
		j += s[i] == s[j];
        p[i] = j;
    }
    return p;
}

vector<int> kmp(string& s, string& t) {
    int n = (int)s.size(), m = (int)t.size();
    string q = s + "&" + t;
    vector<int> res, c = pi(q);
    for (int i = n + 1; i < n + m + 1; i++) {
        if (c[i] == n) res.push_back(i - 2 * n);
    }
    return res;
}
