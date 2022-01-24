def solution(stones, k):
    left = 1
    right = 200000000
    while left <= right:
        temp = stones.copy()
        mid = (left + right) // 2  # 살 수 있는 친구들임
        cnt = 0
        for t in temp:
            if t - mid <= 0:  # 현재 돌에서 인원 빼야됨 그 인원 만큼 돌 밟으니까
                cnt += 1
            else:
                cnt = 0
            if cnt >= k:  # 그게 k보다 커버리면 나감
                break
        if cnt >= k:  # 그래서 cnt가 k보다 크면 인원 내려보고
            right = mid - 1
        else:  # 아니면 더 올려봄
            left = mid + 1

    return left
