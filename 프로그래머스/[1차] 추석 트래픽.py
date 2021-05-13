def solution(lines):
    answer = 0
    arr =[]
    for line in lines:
        time = line.split(' ')[1]
        end = time.split(':')
        endTime = int(end[0])*60*60 * 1000 + int(end[1])*60 * 1000 + float(end[2]) * 1000
        startTime = endTime - float(line.split(' ')[2].replace('s','')) * 1000 + 1
        arr.append([startTime,endTime])
        
    ret = 1
    
    for i in range(0,len(arr)):
        
        st = arr[i][0]
        ed = arr[i][1]
        cntA = 0
        cntB = 0
        for k in range(0 ,len(arr)):
            if arr[k][0] < st + 1000 and arr[k][1] >= st: cntA+=1
            
            if arr[k][0] < ed + 1000 and arr[k][1] >= ed: cntB+=1
            
                
        
        ret = max(ret,cntA,cntB)

    
    answer = ret 
            
        
    return answer