import requests, json

url = 'http://ec2-3-34-252-153.ap-northeast-2.compute.amazonaws.com:8080/api/amount'

data ={'bin_name':'inhafront', 'plastic_amount' : '132','paper_amount':'24', 'water_amount':'54'}
headers={'Content-Type':'application/json'}
print("send start")
response = requests.post(url,headers=headers, data= json.dumps(data))
#response = requests.post(url,data = json.dumps(data))
print("send end")

#print(response.status_code)
#print(response.data)
print(response)
print(response.text)