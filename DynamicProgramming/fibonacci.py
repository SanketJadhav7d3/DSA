

def fib(n):
    global calls
    calls += 1
    if n <= 2: return 1
    return fib(n - 1) + fib(n - 2)

def optimized_fib(n, memo = {}):
    global calls
    calls += 1
    if n in memo: return memo[n]

    if n <= 2: return 1

    memo[n] = optimized_fib(n - 1, memo) + optimized_fib(n - 2, memo)

    return memo[n]


