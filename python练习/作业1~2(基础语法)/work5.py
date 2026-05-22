timenum=int(input('please input a int type number:'))
minutes=timenum%60
timenum//=60
hours=timenum%24
timenum//=24
days=timenum%365
timenum//=365
years=timenum
print(f"years:{years},days:{days},hours:{hours},minutes:{minutes}")