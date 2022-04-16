import requests

headers = {
    'authority': 'cdn-rili.jin10.com',
    'accept': 'application/json, text/plain, */*',
    'accept-language': 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6',
    'origin': 'https://www.jin10.com',
    'referer': 'https://www.jin10.com/',
    'sec-ch-ua': '^\\^',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '^\\^Windows^\\^',
    'sec-fetch-dest': 'empty',
    'sec-fetch-mode': 'cors',
    'sec-fetch-site': 'same-site',
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.75 Safari/537.36 Edg/100.0.1185.39',
}

params = (
    ('_', '202204150104'),
    ('date', '2022-04-14T17:32:54.718Z'),
)

response = requests.get('https://cdn-rili.jin10.com/data/2022/0415/economics.json', headers=headers, params=params)

print(response)