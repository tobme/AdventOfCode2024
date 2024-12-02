from datetime import date
import requests
import os.path

today = date.today()

year = today.year
day = today.day

print(year)
print(day)

path = str(day) + "/InputData.txt"

if (os.path.isfile(path) is False):
    cookies = {'session': '53616c7465645f5fc2f3de2c4bf1edba8c9e185da767de9ba6df45cc3d8ddaddd582c1f5321107322db4a832dc0a92156440856f3da902f86fac00c0081326a4'}

    url = f"https://adventofcode.com/{year}/day/{day}/input"

    r = requests.get(url=url, cookies=cookies)

    data = r.text

    f = open(path, "w")
    f.write(data)
