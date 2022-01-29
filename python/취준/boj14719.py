# import sys
# input =sys.stdin.readline

# h,w= map(int, input().split())

# arr= list(map(int, input().split()))

# ans=0

# lt ,rt= 0, w-1
# lt_max , rt_max = arr[lt], arr[rt]

# while lt<rt:
#     lt_max , rt_max = max(arr[lt], lt_max), max(arr[rt], rt_max)
#     if lt_max<=rt_max:
#         ans +=lt_max - arr[lt]
#         lt+=1
#     else:
#         ans +=rt_max - arr[rt]
#         rt-=1

# print(ans)
import sys
input =sys.stdin.readline
st=[]
ans=0
h,w= map(int, input().split())

arr= list(map(int, input().split()))
for i in range(w):
    while st and arr[i] > arr[st[-1]]: 
        top = st.pop()
        if not len(st):
            break

        dist = i-st[-1] -1
        waters = min(arr[i] , arr[st[-1]])- arr[top]
    
        ans+=dist * waters

    
    st.append(i)

print(ans)