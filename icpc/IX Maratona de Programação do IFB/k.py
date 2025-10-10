p = 1

res = {}
for j in range(2000):
    cont = 0
    p *= (j+1)

    p_ = p
    while (p_ % 10 == 0):
        cont += 1
        p_ //= 10

    res[cont] = j

for i in range(500):
    if i in res.keys():
        print(i, res[i]);
    else:
        print(i, -1);
