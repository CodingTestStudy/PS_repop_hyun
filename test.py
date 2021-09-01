record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
answer = []
dic={}
cnt = 1
nick =[]
for _ in range(0,len(record)+1):
    nick.append("")
        
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