

def solution(lines):
    answer = 0
    s_time = []
    e_time = []

    for t in lines:
        time = t.split(" ")
        s_time.append(get_start(time[1], time[2]))
        e_time.append(to_time(time[1]))
    for i in range(len(lines)):
        cnt = 0
        cur = e_time[i]
        for j in range(i, len(lines)):
            if cur-s_time[j] < 1000:
                cnt += 1
        answer = max(answer, cnt)
    return answer


def to_time(time):
    hour = int(time[:2]) * 3600
    minute = int(time[3:5]) * 60
    second = int(time[6:8])
    millisecond = int(time[9:])
    print(millisecond)
    print((hour + minute + second) * 1000 + millisecond)


def get_start(time, dur):
    m_time = dur[:-1]
    int_sec = int(float(m_time) * 1000)
    return to_time(time) - int_sec+1
