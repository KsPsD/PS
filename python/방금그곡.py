import sys
import math
input = sys.stdin.readline


def re(s):
    return s.replace('C#', 'c').replace('D#', 'd').replace('F#', 'f').replace('G#', 'g').replace('A#', 'a')


m = "ABC"
musicinfos = ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]


datalen = len(musicinfos)
m = re(m)
ans = ['(None)', 0]
for music in musicinfos:
    tmp = music.split(",")
    start_hour = tmp[0].split(':')[0]
    start_minute = tmp[0].split(':')[1]
    end_hour = tmp[1].split(":")[0]
    end_minute = tmp[1].split(":")[1]
    t_hour = 60*(int(end_hour)-int(start_hour)) + \
        (int(end_minute)-int(start_minute))
    title = tmp[2]
    song = (re(tmp[3]) * math.ceil(t_hour/len(tmp[3])))[:t_hour]

    if m in song and ans[1] < t_hour:
        ans[0] = title
        ans[1] = t_hour
print(ans[0])
