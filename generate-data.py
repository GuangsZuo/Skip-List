#coding=utf-8

# this is used to generated test dat to test skip-list correctness.
import sys
import random


if __name__ == "__main__" :

	n = 100000
	m = 10000
	print("%d %d"%(n,m))
	random.seed()
	s = {}
	for i in range(n):
		x = random.randint(1,10000)
		if not s.get(x):
			s[x] = 0
		s[x] += 1
		print(x)

	for i in range(m):
		y = random.randint(1,10000)
		print(y)
		if not s.get(y):
			ans = 0
		else:
			ans = s[y]
		print(ans)

