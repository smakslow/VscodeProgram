n , k = map(int , input().split())

def dfs(n , k):
    if k == 1 << n -1:
        return n
    if k < 1 << n -1:
        return dfs(n - 1, k)
    return dfs(n - 1,k - (1 << n - 1))
print(dfs(n,k))