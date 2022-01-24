# import sys

# input = sys.stdin.readline

# enter, leave = [1, 4, 2, 3], [2, 1, 4, 3]

# # mod_leave = leave.copy()
# cur_list = []
# answer = [0 for _ in range(len(enter)+1)]
# for cur in enter:
#     cur_list.append(cur)
#     print("curlist:", cur_list)
#     for in_ in cur_list[::-1]:
#         if in_ == leave[0]:
#             print(in_, leave, cur_list)
#             leave.pop(0)
#             cur_list.remove(in_)
#             for x in cur_list:
#                 print("cur", cur_list, leave)
#                 if x != in_:
#                     answer[in_] += 1
#                     answer[x] += 1

# print(answer[1:])


# def solution(enter, leave):
#     answer = [0] * len(enter)
#     room = []
#     e_idx = 0
#     for l in leave:
#         while l not in room:
#             e_idx += 1
#             room.append(enter[e_idx])
#         room.remove(l)
#         for p in room:
#             answer[p - 1] += 1
#         answer[l - 1] += len(room)

#     return answer

# def solution(enter, leave):
#     answer = [[] for _ in range(len(enter) + 1)]
#     meeting = []

#     # two-pointer
#     i, j = 0, 0
#     while i < len(enter) or j < len(leave):
#         if leave[j] not in meeting:
#             answer[enter[i]] = meeting[:]  # enter[i]가 회의실에 들어가기 전 기존 사람들
#             meeting.append(enter[i])
#             i += 1
#         else:
#             meeting.remove(leave[j])
#             j += 1

#     print(answer)
#     for idx, person in enumerate(answer):
#         for i in person:  # 예) 1번은 [2, 4]와 만났다고 하면 2번, 4번 인덱스에는 1번 정보가 없음
#             answer[i].append(idx)
#     print(answer)
#     return [len(set(i)) for i in answer][1:]


# solution([1, 4, 2, 3], [2, 1, 3, 4])
