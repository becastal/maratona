// Inicializacao
map<string, double> m = {{"Joao", 1.15},{"Maria", 7}};

// Adicionando um novo elemento
m["Roberto"] = 10.0;

// Atualizando um elemento
m["Joao"] = 0.0;

// Procura por uma chave no map
auto it = m.find("Roberto");

// Excluindo elementos
m.erase("Maria");
