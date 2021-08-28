import re


answer = "=.="
    
answer = answer.lower()
str = "~!@#$%^&*()=+[{]}:?,<>/"

for st in str:
    answer = answer.replace(st,'')

while(1):
    if answer == answer.replace("..",".") :
        break
    
    answer = answer.replace("..",".")
    


print(answer)


if answer[0] == "." and len(answer) > 1:
        answer = answer[1:]
elif answer[0] == "." and len(answer) == 1:
        answer = ""
        
if  len(answer) > 1 and answer[-1] == "." :
    answer = answer[:-1]
elif len(answer) == 1 and answer[-1] == ".":
    answer = ""
              
  
if answer == "": answer+= "a"
    
if len(answer) >= 16 :
        answer = answer[0:15]
        
if answer[-1] == ".":
        answer = answer[:len(answer)]
    
while len(answer) < 3:
    answer += answer[-1]
    

  
print(answer)     