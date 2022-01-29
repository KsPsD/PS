import itertools

def next(y,x,dir):
    if dir % 3 ==0:
        y+=1
    elif dir %3 ==1:
        x+=1
    else:
        y-=1
        x-=1
    return y,x
def solution(n):
    answer = []
    arr= [[0 for j in range(1,i+1)] for  i in range(1,n+1)]
    y,x=  -1,0
    idx=1
    for i in range(n):
        for j in range(i,n):
            y,x = next(y,x,i)
            arr[y][x] =idx
            idx+=1
   

    
    
    return list(itertools.chain(*arr))