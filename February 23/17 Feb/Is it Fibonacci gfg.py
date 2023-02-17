    def solve(self, N, K, GeekNum):
        #your code goes here
        series = GeekNum
        if(N<=K):
            return series[N-1]
        
        sum =0
        for i in range(len(GeekNum)):
            sum = sum + series[i]
        
        for i in range(K,N):
            series.append(sum)
            sum = sum + sum
            sum = sum - series[i-K]
        
        return series[N-1]
