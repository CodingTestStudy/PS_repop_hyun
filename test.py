import re

str1 = "aa+b"
str2 = "aab"
str1= re.sub('[^A-Za-z]','',str1);
str2 =re.sub('[^A-Za-z]','',str2);
str1 =str1.lower()
str2 = str2.lower()
a = list()
b= list()

  
for i in range(len(str1)):
    if i == len(str1)-1:break
            
    tmp =""
    tmp += str1[i] + str1[i+1]
    a.append(tmp)
    
for i in range(len(str1)):
    if i == len(str2)-1:break
            
    tmp =""
    tmp+= str2[i] + str2[i+1]
    b.append(tmp)
    
