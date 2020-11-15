from cs50 import get_int
# take user input
while True:
    height= get_int("Height: ")
    if height>0:
        break
# making hash figure using nested for loop
for row in range (1, height+1):
    for spc in range (0, height-row):
        print(" ", end="")
    for col in range (0, row):
        print("#", end="")
    print("  ", end="")
    for col2 in range (0, row):
        print("#",end="")
    print()