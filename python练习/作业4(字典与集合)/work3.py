
def test(users):
    if(users.get('xiaohong')!=None):
       print(users.get('xiaohong'))
    else:
       print("not found")
    pass
users={}
test(users)
users['xiaohong']=1
test(users)
