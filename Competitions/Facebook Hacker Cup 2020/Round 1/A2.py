import sys
# file_ = 'input.txt'
file_ = 'perimetric_chapter_2_validation_input.txt'
sys.stdin = open(file_,'r')
sys.stdout = open('output.txt','w')

def get_next(arr, a,b,c,d, i, k):
    if(i<k):
        return arr[i]
    next_ = ((a%d)*(arr[i-2]%d))%d
    next_ = (next_ + ((b%d)*(arr[i-1]%d))%d)%d
    next_ = (next_ + c%d)%d
    arr.append(next_+1)

def sort_list(list1, list2): 
    zipped_pairs = zip(list2, list1) 
    z = [x for _, x in sorted(zipped_pairs)] 
    return z 

def check_overlap(x1,x2,y1,y2):
    return x1 <= y2 and y1 <= x2

def get_overlap(x1,x2,y1,y2):
    return min(x2,y2) - max(x1,y1)

t = int(input())
for case_ in range(1,t+1):
    n,k = list(map(int,input().strip().split()))
    L = list(map(int,input().strip().split()))
    Al, Bl, Cl, Dl = list(map(int,input().strip().split()))
    W = list(map(int,input().strip().split()))
    Aw, Bw, Cw, Dw = list(map(int,input().strip().split()))
    H = list(map(int,input().strip().split()))
    Ah, Bh, Ch, Dh = list(map(int,input().strip().split()))
    
    for i in range(n):
        get_next(L,Al, Bl, Cl, Dl, i, k)
        get_next(W,Aw, Bw, Cw, Dw, i, k)
        get_next(H,Ah, Bh, Ch, Dh, i, k)
    
    P = []
    intervals = []
    for i in range(n):
        curr = 2*(W[i]+H[i])
        # print(L[i],W[i],H[i],curr)
        new_arr = []
        if i==0:
            P.append(curr)
            intervals.append([L[i],L[i]+W[i],curr])
            # print("New",L[i],L[i]+W[i],curr)
            # print("~~",*intervals)
            continue
        x1,x2 = L[i],L[i]+W[i]
        new_x1, new_x2 = x1,x2
        sum_ = curr
        zzz = 0
        flag = False
        for p in intervals:
            y1,y2,val = p
            if(check_overlap(x1,x2,y1,y2)):
                new_x1 = min(new_x1,y1)
                new_x2 = max(new_x2,y2)
                overlap = get_overlap(x1,x2,y1,y2)
                # print(sum_)
                sum_+=(val-2*overlap-2*H[i])
                # print('overlap',x1,x2,y1,y2,overlap,val,H[i],sum_)
                flag = True
            else:
                new_arr.append(p)
                zzz+=p[-1]
        # if not flag:
        #     sum_ += P[i-1]
        # print("New",new_x1,new_x2,sum_)
        new_arr.append([new_x1, new_x2, sum_])
        intervals = new_arr
        # print("~~",*intervals)

        P.append(sum_+zzz)
    # print(*L)
    # print(*H)
    # print(*W)
    # print(*P)
    answer = 1
    mod = 1000000007
    for p in P:
        answer = (answer*p)%mod
    print("Case #{}:".format(case_),answer)
