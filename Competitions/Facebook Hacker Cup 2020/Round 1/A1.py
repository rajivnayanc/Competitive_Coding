import sys
file_ = 'perimetric_chapter_1_input.txt'
sys.stdin = open(file_,'r')
sys.stdout = open('output.txt','w')

def get_next(arr, a,b,c,d, i, k):
    if(i<k):
        return arr[i]
    next_ = ((a%d)*(arr[i-2]%d))%d
    next_ = (next_ + ((b%d)*(arr[i-1]%d))%d)%d
    next_ = (next_ + c%d)%d
    arr.append(next_+1)

t = int(input())
for case_ in range(1,t+1):
    n,k,w = list(map(int,input().strip().split()))
    L = list(map(int,input().strip().split()))
    Al, Bl, Cl, Dl = list(map(int,input().strip().split()))
    H = list(map(int,input().strip().split()))
    Ah, Bh, Ch, Dh = list(map(int,input().strip().split()))
    for i in range(n):
        get_next(L,Al, Bl, Cl, Dl, i, k)
        get_next(H,Ah, Bh, Ch, Dh, i, k)
    
    P = []

    for i in range(n):
        if i==0:
            P.append(2*(w+H[i]))
            continue
        curr = 2*(w+H[i])
        if(H[i]<=H[i-1]):
            if((L[i-1]+w)>=L[i]):
                diff = 2*abs(L[i-1]+w-L[i])
                neg = 2*min(H[i-1],H[i])
                P.append(P[i-1]-diff-neg+curr)
            else:
                P.append(P[i-1]+curr)
        else:
            if((L[i-1]+w)>=L[i]):
                z = i-1
                max_H = H[i-1]
                ind = i-1
                while(z>=0 and L[z]+w>=L[i]):
                    if(H[z]>max_H):
                        ind = z
                        max_H = H[z]
                    z-=1
                diff = 2*abs(L[ind]+w-L[i])
                neg = 2*min(H[ind],H[i])
                P.append(P[ind]-diff-neg+curr)
            else:
                P.append(P[i-1]+curr)
            

    answer = 1
    mod = 1000000007
    for p in P:
        answer = (answer*p)%mod
    print("Case #{}:".format(case_),answer)
