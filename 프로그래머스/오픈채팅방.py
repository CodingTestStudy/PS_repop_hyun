def solution(record):
    answer = []
    dic={}
    cnt = 1
    nick =[]
    for _ in range(0,len(record)+1):
        nick.append(" ")

    ret = []
    for x in record:
        tmp = x.split()
        if len(tmp) >= 3:
            if tmp[1] not in dic:
                dic[tmp[1]] = cnt
                cnt+=1
            nick[dic[tmp[1]]] = tmp[2]
            if tmp[0] == "Enter":
                ret.append(["E",dic[tmp[1]]])
        else :
            if tmp[0] == "Leave":
                ret.append(["L",dic[tmp[1]]])





    for e in ret:
        if e[0] == "E":
            answer.append(nick[e[1]] + "님이 들어왔습니다.")
        elif e[0] == "L":
            answer.append(nick[e[1]] + "님이 나갔습니다.")





    return answer