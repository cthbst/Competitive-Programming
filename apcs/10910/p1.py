# Copyright (C) Algo Seacow. 2020. All Rights Reserved.

a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
n = int(input())

ans = -10**9
for i in range(n + 1):
    j = n - i
    ans = max(ans, a * i * i + b * i + c + d * j * j + e * j + f)
print(ans)
