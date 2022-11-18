import random
import sys

random.seed(sys.argv[1])

if __name__ == '__main__':
    N = int(sys.argv[2])
    M = int(sys.argv[3])
    K = int(sys.argv[4])
    print(N,M,K)
    for i in range(N):
        for j in range(M):
            if (j != 0):
                print(" ",end="")
            print(random.randint(1,K),end="")
        print("")
    