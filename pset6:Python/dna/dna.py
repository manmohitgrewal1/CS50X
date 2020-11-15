import sys
import csv

if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit()

with open(sys.argv[1]) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    strs=[]
    profiles= []
    plug= False
    for run in csv_reader:
        if plug == False:
            run.pop(0)
            plug=True
            strs= run
        else:
            profiles.append(run)
    dnaSample=[]
    with open(sys.argv[2])as text:
        csvText= csv.reader(text)
        for run in csvText:
            dnaSample=run
            break
    key=0
    dnaRecord={}
    for large in range(0, len(strs)):
        position=0
        prevPosition=0
        prevCount=0
        count=0
        seq= False
        length= len(strs[large])
        if large>=0:
            while True:
                position=dnaSample[0].find(strs[large], position)
                if position == -1:
                    count=0
                    break
                elif position != -1 and position ==0:
                    prevPosition= position 
                    count+=1
                elif position != -1 and (position - length != prevPosition):
                    count=0
                    count+=1
                    prevPosition= position
                    if prevCount< count:
                        prevCount=count    
                elif position != -1 and (position - length == prevPosition):
                    count+=1
                    prevPosition= position
                    if prevCount< count:
                        prevCount=count
                position += 1 
            dnaRecord[key]=prevCount
            key+=1
output=""   
for run in profiles:
    checker=False
    for i in range(0, len(run)-1):
        if  dnaRecord[i] ==  int(run[i+1]):
            checker= True
            output= run[0]
            
        else:
            checker= False
            output= ""
            break
    if checker== True:
        print(output)
        sys.exit()
print("No match")
        