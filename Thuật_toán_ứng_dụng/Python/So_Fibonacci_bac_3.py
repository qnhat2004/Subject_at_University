def f(n, memo = {0: 0, 1: 1, 2: 2}):
    if n not in memo:
        k, l = divmod(n, 3)
        if l == 0:
            memo[n] = f(2*k, memo)
        elif l == 1:
            memo[n] = f(2*k, memo) + f(2*k+1, memo)
        else: # l == 2
            memo[n] = f(2*k, memo) + f(2*k+1, memo) + f(2*k+2, memo)
    return memo[n]

n = int(input("Nhap n = "))
print(f"f({n}) =", f(n))
