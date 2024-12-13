a = input()
b = input()

asta, astb = 0, 0
for ai in a:
	if (ai == '*'):
		asta += 1;

for bi in b:
	if (bi == '*'):
		astb += 1;

A, B = [], []

for i in range(1 << asta):
	cont = 0

	sai = ""
	for j in range(len(a)):
		if a[j] == '*':
			sai += '1' if i & (1 << cont) else '0'
			cont += 1
		else:
			sai += a[j]
	A.append(sai)

for i in range(1 << astb):
	cont = 0

	sbi = ""
	for j in range(len(b)):
		if b[j] == '*':
			sbi += '1' if i & (1 << cont) else '0'
			cont += 1
		else:
			sbi += b[j]
	B.append(sbi)

def fim():
	for i in A:
		for j in B:
			if int(i, 2) % int(j, 2) == 0:
				print(i)
				return
fim()
