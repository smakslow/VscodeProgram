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
n = int(input())
a = input().split()
int(a[i]) #使用时转换

#或者这样写
a = [int(i) for i in input().split()]


#二维数组
first = input()
n, m, T = [int(i) for i in first.split()]

a = []       #这是二维数组
for i in range(m):
    a.append([int(i) for i in input().split()])
