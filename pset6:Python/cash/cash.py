from cs50 import get_float

# Limiting the input to positive rational number
while True:
    coin= get_float("Changed owed: ")
    if coin>0:
        break

# convert the float value to int
coin= coin*100
# Declaring a variable to count number to changes owned
counter=0
# calculating the change
while coin!=0:
    if coin>=25:
        coin-=25
        counter+=1
    elif coin>=10:
        coin-=10
        counter+=1
    elif coin>=5:
        coin-=5
        counter+=1
    elif coin>=1:
        coin= coin-1
        counter+=1
print(counter)

