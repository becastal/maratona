/*
	prefix function

	descricao:
		retorna pi(s), sendo pi[i] o maior prefixo de s[0...i] que
		eh tambem sufixo de s[0..1]

	complexidade:
		o(|s|)
*/
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
