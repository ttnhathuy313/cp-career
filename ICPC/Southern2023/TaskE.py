d = [[0 for _ in range(1005+1)] for _ in range(2*1005+1)]

def kth_balanced(n, k):
    ans = ''
    depth = 0
    for i in range(2*n):
        if depth + 1 <= n and d[2*n-i-1][depth+1] >= k:
            ans += '('
            depth += 1
        else:
            ans += ')'
            if depth + 1 <= n:
                k -= d[2*n-i-1][depth+1]
            depth -= 1
    return ans

p = [0 for _ in range(1005)]

n = 1000
d[0][0] = 1
for i in range(1, 2*n+1):
    d[i][0] = d[i-1][1]
    for j in range(1, n):
        d[i][j] = d[i-1][j-1] + d[i-1][j+1]
    d[i][n] = d[i-1][n-1]

while True:
    try:
        s = input()
        if s[0] == '1':
            problem_type,n,k = map(int, s.split())
            s = kth_balanced(n, k)
            for i in range(len(s)):
                if s[i] == '(':
                    print(i + 1, end=' ')
            for i in range(len(s)):
                if s[i] == ')':
                    print(i + 1, end=' ')
            print()
        elif s[0] == '2':
            aa = list(map(int, s.split()))
            n = aa[1]
            p = aa[2:]
            st = [0 for i in range(2 * n)]
            for i in range(0, n):
                st[p[i]-1] = 1
            depth = 0
            res = 0
            for i in range(2*n):
                if st[i] == 1:
                    depth += 1
                else:
                    res += d[2*n-i-1][depth+1]
                    depth -= 1
            print(res + 1)
    except EOFError:
        break