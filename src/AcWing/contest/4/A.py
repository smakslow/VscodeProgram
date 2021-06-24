input()
s = input()
a, b = 0, 0
for c in s:
    if c == 'A':
        a += 1
    else:
        b += 1
ans = ""
if a > b:
    ans = "A"
elif a < b:
    ans = "B"
else:
    ans = "T"
print(ans)
