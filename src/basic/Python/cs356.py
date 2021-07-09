# 爬!
# 获取https://docs.google.com/spreadsheets/d/1zfw8nPvJeewxcFUBpKUKmAVE8PjnJI7H0CKimdQXxr0/htmlview下PDF文档
# 获取https://cs356.stanford.edu/ CS356——计算机网络安全主题下所有pdf
 
from requests import get 
from requests.exceptions import ReadTimeout
from bs4 import BeautifulSoup
 
def main():
    url = 'https://cs356.stanford.edu/'
    html = request_stanford(url)
    url_list = parse(html)
    new_list = new(url_list)
    download(new_list)
    return 0
 
 
# 获取网站源代码
def request_stanford(url):
    try:
        header = {
            'user-agent': 'Mozilla/5.0'
                        '(Windows NT 10.0; Win64; x64)'
                        'AppleWebKit/537.36 (KHTML, like Gecko)'
                        'Chrome/91.0.4472.114 Safari/537.36 OPR/77.0.4054.172'
        }
        response = get(url, headers = header)
     
    except ReadTimeout as e:
        print(e)
    return response.text
 
# 调用BeautifulSoup get_url_list
def parse(html):
    soup = BeautifulSoup(html, features = 'lxml')
    s = soup.find_all('a')
    url_list = []
    for link in soup.find_all('a'):
        url = link.get('href')
        url_list.append(url)
    url_list = list(filter(lambda url_str: 'pdf' in url_str, url_list))
    return url_list
 
 
# 补全URL
def new(*url_list):
    new_list = []
    for urls in url_list:
        for url in urls:
            if 'http' in url:
                new_list.append(url)
            else:
                url = 'https://cs356.stanford.edu/' + url
                new_list.append(url)
    return new_list
 
 
 
 
# build_folder download
def download(*urls):
    folder_path = 'E:\Stanford\cs256_Topics in Computer and Network Security'
    i = 0
    for url in urls:
        for u in url:
            print('正在下载：{}'.format(u))
            filename = str(u).split('/')[-1]
            filename = '[' + str(i) + ']' + filename
            i = i + 1
            filepath = folder_path + '/' + filename
            pdf = get(u)
            with open(filepath,'wb') as book:
                book.write(pdf.content)
    return 0
 
if __name__ == '__main__':
    main()