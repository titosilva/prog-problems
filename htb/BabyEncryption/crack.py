import PyPDF2

ENCRYPTED_FILE_PATH = './BabyEncryption.zip'


with open(ENCRYPTED_FILE_PATH, mode='rb') as f:    
    i = 0
    while True:
        try:
            pwd = input()
        except:
            print(f"Failed to read {i}")

        reader = PyPDF2.PdfReader(f, password=pwd)
        print(f"Pwd: {pwd}")
        break
        try:    
            pass
        except:
            if i % 1000 == 0:
                print(i)
                print()
            pass
        i+=1
    