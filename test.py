import datetime

timeStr = '2018-07-28 12:11:32'
Thistime = datetime.datetime.strptime(timeStr,'%Y-%m-%d %H:%M:%S')
arr =[]
lines = ["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"]


for line in lines:
    time = line.split(' ')[1]
    end = time.split(':')
    print(float(line.split(' ')[2].replace('s','').replace('.','')) )
    endTime = int(end[0])*60*60 * 1000 + int(end[1])*60 * 1000 + int(end[2].split('.')[0]) * 1000 + int(end[2].split('.')[1])
    startTime = endTime - int(line.split(' ')[2].replace('s','').replace('.','')) + 1
    arr.append([startTime,endTime])


print(len(arr))