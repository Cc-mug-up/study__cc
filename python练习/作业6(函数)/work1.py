from datetime import datetime
print(datetime.now())
dt1=datetime.now()
st1=dt1.timestamp()
dt2=datetime(2026,1,1,0,0)
st2=dt2.timestamp()
st=st1-st2
print(st/60/60//24+1)