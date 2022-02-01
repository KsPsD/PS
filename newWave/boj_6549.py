import sys
input= sys.stdin.readline
arr=[]
# while 1:
#     input_arr= list(map(int, input().split()))
#     if input_arr[0]==0:
#         break

#     ans=0
#     st=[]
#     arr= input_arr[1:]

#     for val in arr:
#         tmp= 0
#         while st and st[-1][0] > val:
#             tmp+= st[-1][1]
#             ans = max(ans, tmp * st[-1][0])
#             st.pop()

#         tmp+=1
#         st.append([val, tmp])

#     tmp=0
#     while st:
#         tmp+= st[-1][1]
#         ans = max(ans, tmp * st[-1][0])
#         st.pop()

#     print(ans)

#여기는 분할 정복


def solve(lt,rt):
    global arr
    if lt==rt:
        return arr[lt]
    mid= (lt+rt)//2
    res= max(solve(lt,mid), solve(mid+1,rt))
    lo = mid
    hi=  mid+1
    height = min(arr[lo], arr[hi])
    res = max(res, 2*height)

    while lt<lo or hi<rt:
        if hi<rt and (lt == lo or arr[lo-1] <arr[hi+1]):
            hi+=1
            height= min(height, arr[hi])
        else:
            lo-=1
            height= min(height, arr[lo])

        res= max(res, 2*height)
    return res

while 1:
    input_arr= list(map(int, input().split()))
    if input_arr[0]==0:
        break
    n= input_arr[0]
    arr= input_arr[1:]
    print(solve(0,n-1))

    