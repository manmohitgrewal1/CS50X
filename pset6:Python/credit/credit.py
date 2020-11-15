from cs50 import get_int

# Get user input
card= get_int("Number: ")
card_bckp= card
c_len= len(str(card))
sl_multi,pro_sum,pro_brkdwn,store ,unpro_sum, unpro, check_start= 0,0,0,0,0,0,0

for extract in range (1, c_len+1):
    if extract%2==0:
        sl_multi= card%10
        card=card//10
        store=sl_multi*2
        if store>9:
            while True:
               pro_brkdwn= store%10
               pro_sum= pro_sum+ pro_brkdwn
               store=store//10
               if pro_brkdwn==1:
                   break
        elif store<=9:
            pro_sum= pro_sum + store

    elif extract%2!=0:
        unpro=card%10
        card=card//10
        unpro_sum+=unpro

# print(unpro_sum+pro_sum)
algo_sum= unpro_sum+pro_sum
if algo_sum%10!= 0:
    print ("INVALID")
elif algo_sum%10== 0 and c_len==15 or c_len==16 or c_len==13:
    if c_len==16:
        check_start=card_bckp//pow(10,14)
        if check_start==51 or check_start==52 or check_start==53 or check_start==54 or check_start==55:
            print("MASTERCARD")
        else:
            check_start=card_bckp//pow(10,15)
            if check_start==4:
                print("VISA")
            else:
                print("INVALID")

    elif c_len==15:
        check_start=card_bckp//pow(10,13)
        if check_start==34 or check_start==37:
            print("AMEX")
        else:
            print("INVALID")
    elif c_len==13 :
        check_start=card_bckp//pow(10,12)
        if check_start==4:
            print("VISA")
        else:
            print("INVALID")

