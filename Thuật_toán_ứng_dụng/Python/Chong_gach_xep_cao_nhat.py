n = int(input())
a = list(map(int, input().split()))
ans, max_high = 0, float('inf') # infinity
a.sort(reverse = True)
for i in range(n):
  ans += 1
  max_high = min(max_high - 1, a[i])
  if (max_high == 0): break
print(ans)
