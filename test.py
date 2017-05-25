import pylyra
import base64

status = pylyra.lyra(128, 'abcedfgh', 'bedadasd9879', 10, 4096)
print('|'.join(hex(x) for x in status))
print(base64.b64encode(status))
