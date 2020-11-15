import math
# Take user input 
text= input("Text: ")
letters =0
words =0
sentences= 0
for run in text:
    # print(run)
    if run == " ":
        words+=1
    elif  run == "!" or run == "?" or run == ".":
        sentences+=1
    else:
        letters+=1
        
words+=1
L= (letters / words)*100
S= (sentences / words)*100
index= 0.0588 * L - 0.296 * S - 15.8;
grade= math.floor(index)
if grade >16:
    print("Grade 16+\n")
if grade<1:
    print("Before Grade 1\n")
else:
    print("Grade {}".format(grade))