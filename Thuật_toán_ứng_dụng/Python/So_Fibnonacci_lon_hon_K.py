k = int(input())
a, b = 0, 1
while a <= k:
  b = a + b
  a = b - a
print(a)
