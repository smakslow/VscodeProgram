a , b ,c = map(int, input().split())
print(a,b,c)

arr = list(map(int ,input().split()))

t = tuple(map(int ,input().split()))

print(arr)

print(t)

# 读入多个输入
while True:
    try:
        a, b = map(int,input().split())

        print(a + b)
    except:  #读到文件末尾抛出异常结束循环
        break