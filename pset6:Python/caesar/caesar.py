from sys import argv
from cs50 import get_string
if len(argv)!=2:
    print("ERROR-404")
n= int(argv[1])

def get_ascii(plaintext):
    pt=ord(plaintext)
    if pt>=97 and pt<=122:
        pt-=97
        nw_plaintext= (pt+n)%26
        x=chr(nw_plaintext+97)
        print(f"{x}", end="")
    elif pt>=65 and pt<=90:
        pt-=65
        nw_plaintext= (pt+n)%26
        x=chr(nw_plaintext+65)
        print(f"{x}", end="")
plaintext= get_string("plaintext: ")
print("ciphertext: ", end="")
for run in plaintext:
    if run==" ":
        print(" ", end="")
        continue
    else:
        get_ascii(run)
print()