import pylyra
import base64

status = pylyra.lyra(1,2)
print(status)
print(base64.b64encode(status))
