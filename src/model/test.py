chars = ['a', 'b', 'c', 'd']

for i, char in enumerate(chars):
    print(i, char)

s = 'abcd'
l = list(s)
print(l)

for i, char in enumerate(l):
    print(i, char)


d = {'name': 'zhangsan', 'age': 18, 'sex': 'm'}

d['score'] = 99

for item in d.items():
    print(item)

for key, val in d.items():
    print(key, val)

for key in d.keys():
    print(key, end=' ')
print()
for value in d.values():
    print(value, end=' ')

m = dict()
str = "hello world"
for c in str:
    if m.get(c) != None:
        m[c] = m[c] + 1
    else:
        m[c] = 1
for item in m.items():
    print(item)


