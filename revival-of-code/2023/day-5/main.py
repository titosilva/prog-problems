from hashlib import md5 

id = input()

idx = 0
pswd = ''
while len(pswd) < 8:
    s = id + str(idx)
    hex_hash = md5(s.encode('utf-8')).hexdigest()

    if hex_hash[:5] == '00000':
        print(f'Index: {idx}, hash: {hex_hash}')
        pswd += hex_hash[5]

    idx += 1

print(pswd)