from datetime import date
print(date.today())
from datetime import time
print(time(23,20,35))

from datetime import datetime
dt=datetime.now()
print(dt)
print(dt.strftime('%a,%b %d %Y %H:%M'))

dt=datetime(2017,2,3,23,29)
print(dt)
ts=dt.timestamp()
print(ts)
print(datetime.fromtimestamp(ts))