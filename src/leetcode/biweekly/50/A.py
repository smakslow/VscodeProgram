print('We are the {} who say "{}!"'.format('knights', 'Ni'))
print('{0} and {1}'.format('spam', 'eggs'))
print('{1} and {0}'.format('spam', 'eggs'))

table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 7678}
for name, phone in table.items():
    print(f'{name:10} ==> {phone:10d}')


here = 1024
that = 1024
there =  1024
print('变量here在内存中的地址：',id(here))
print('变量there在内存中的地址：',id(there))
print('变量that在内存中的地址：',id(that))