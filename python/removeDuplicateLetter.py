def removeDuplicateLetters(s: str) -> str:
    print(s)
    for char in sorted(set(s)):  # 주어진 문자열에서 중복된 값 제거후 사전순으로 정렬함
        suffix = s[s.index(char):]  # 정렬된 셋에서 가장 먼저 나온 char 부터 나눠서 접미사를 만듬
        print(f"suffix: {suffix}")
        if set(s) == set(suffix):
            # 현재 접미사에서 맨앞 문자열 지우고 재귀돌림
            return char + removeDuplicateLetters(suffix.replace(char, ''))
    return ''


print(removeDuplicateLetters("cbacdcbc"))
