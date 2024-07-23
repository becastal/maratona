import random
q = int(input())
s = f'{q}\n'
for _ in range(q):
	s += str(random.randint(1, 999) / 1000) + ' ';

print(s)
