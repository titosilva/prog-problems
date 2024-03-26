import string
# from secret import MSG

def encryption(msg):
    ct = []
    for char in msg:
        ct.append((123 * char + 18) % 256)
    return bytes(ct)

def decryption(msg):
    dt = []
    for char in msg:
        dt.append(((char - 18) * 179) % 256)
    return bytes(dt)

f = open('./msg.enc','r')
s = f.read()
b = bytes.fromhex(s)
print(decryption(b))
