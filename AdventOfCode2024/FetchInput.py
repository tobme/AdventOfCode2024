from datetime import date
import requests
import os.path

today = date.today()

year = today.year
day = today.day

print(year)
print(day)

if (day > 25):
	exit(0)

path = str(day) + "/InputData.txt"
f = open("session.txt", "r")

if (os.path.isfile(path) is False):
    cookies = {'session': f.read()}

    url = f"https://adventofcode.com/{year}/day/{day}/input"

    r = requests.get(url=url, cookies=cookies)

    data = r.text

    f = open(path, "w")
    f.write(data)
