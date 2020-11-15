import sys
from cs50 import get_string

if len(sys.argv)!=2:
    print("Usage: python vigenere.py k")
    sys.exit(1)
key=sys.argv[1]
for run_key in key:
    if not run_key.isalpha():
       print("Usage: python vigenere.py k")
       sys.exit(1)

def get_baseValue(alpha):
    ascii_ofset= 65 if alpha.isupper() else 97
    nw_alpha=ord(alpha)-ascii_ofset
    return nw_alpha

# user unput for plaintext
plaintext=get_string("plaintext: ")
print("ciphertext: ", end="")
index=0
for run_over_string in plaintext:
    pt_runner=get_baseValue(run_over_string)
    if pt_runner==-65:
        print(" ", end="")
        continue
    elif not run_over_string.isalpha():
        print(run_over_string, end="")
        continue
    else:
        ki=get_baseValue(key[index])
        ci= (pt_runner+ ki)%26
        conv= 65 if run_over_string.isupper() else 97
        nw_ci= chr(ci + conv)
        print(nw_ci, end="")
        if index==len(key)-1:
            index=0
        else:
            index+=1
print()