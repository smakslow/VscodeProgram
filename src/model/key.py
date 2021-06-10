import keyword

print(keyword.kwlist)

list=[1,2,3]
print(' '.join(str(i) for i in list ))


while True:
    try:
        a , b = map(int, input().split())
        c = a + b
        print(a + b)
    except:
        break
