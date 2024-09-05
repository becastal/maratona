/* 
trie

descricao:
	arvore que mantem um dicionario.
	TRIE t() constroi uma trie proa alfabeto das
	letras minustulas. t(tamanho do alfabeto, menor c)
	tambem pode ser usado.

complexidades:
	memoria: o(n|s|);
	insert: o(|s|*sigma)
	erase: o(|s|)
	find: o(|s|) retorna a posicao, -1 se nao achar
	count_pref: o(|s|) numero de strings s eh prefixo
*/

struct TRIE {
	vector<vector<int>> to;
	vector<int> end, pref;
	int sigma; char norm;
	TRIE(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
		to = {vector<int>(sigma)};
		end = {0}, pref = {0};
	}
	void insert(string s) {
		int x = 0;
		for (auto c : s) {
			int &nxt = to[x][c-norm];
			if (!nxt) {
				nxt = to.size();
				to.push_back(vector<int>(sigma));
				end.push_back(0), pref.push_back(0);
			}
			x = nxt, pref[x]++;
		}
		end[x]++, pref[0]++;
	}
	void erase(string s) {
		int x = 0;
		for (char c : s) {
			int &nxt = to[x][c-norm];
			x = nxt, pref[x]--;
			if (!pref[x]) nxt = 0;
		}
		end[x]--, pref[0]--;
	}
	int find(string s) {
		int x = 0;
		for (auto c : s) {
			x = to[x][c-norm];
			if (!x) return -1;
		}
		return x;
	}
	int count_pref(string s) {
		int id = find(s);
		return id >= 0 ? pref[id] : 0;
	}
};
