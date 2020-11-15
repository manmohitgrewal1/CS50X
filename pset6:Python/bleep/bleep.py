from cs50 import get_string
import sys

if len(sys.argv)!=2:
    print("Usage: python bleep.py dictionary")
    sys.exit(1)


def main():
    filename=sys.argv[1]
    set_of_words= set()
    f=open(filename, "r")
    # print(type(f.read()))
    words= str.split(f.read())
    # print(words[0])
    msg= get_string("What message would you like to censor?\n")
    msg_str=str.split(msg)
    # print(msg_str, words)
    # print(len(msg_str))
    chk=0
    for run_over_msg in msg_str:
        chk=0
        for run_over_words in words:
            if run_over_msg== run_over_words:
                for r in range (0, len(run_over_msg)):
                    print("*", end="")
                print(" ", end="")
                chk=1
        if chk==0:
            print(run_over_msg, end=" ")


    print()


if __name__ == "__main__":
    main()
