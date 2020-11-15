from cs50 import get_int
# Take user input
while True:
    height= get_int("Height: ")
    if height >0:
        break
# Nested loop for printing pry
for row in range(1, height+1):
    for space in range (0, height-row):
        print(" ", end="")
    for col in range (0, row):
        print("#", end="")
    print()
