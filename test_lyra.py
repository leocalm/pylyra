import pylyra
import base64


def test_lyra2():
    status = pylyra.lyra(128, 'abcedfgh', 'bedadasd9879', 10, 4096)
    assert b'7MrCWI8loUUIfi+Stm1qEllfsWfOLK3TbSM/sJgpHskCTuUutbaTDvJu/mdyCEH6f4v3E5XgkzfsHxdEpYCFEIZS04E2oMM+y1m8WTEnAzUI7Wgcl1e/1i3GdDFEQNLGLKpt8yTY+P5oP7riSIC/E19ZKx/wUAeD5XcYBI0RHnY=' == base64.b64encode(status)
