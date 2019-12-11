import sys

def main():
    temp = eval(sys.argv[1])
    file = open('temp.txt', 'r')

    Sum = 0;
    under = 0; 
    Temp = 0;
    for line in file.read().split('\n')[2:-1]:
        Temp += 1
        Sum += eval(line)
        if eval(line) < temp:
            under += 1

    avg = Sum / Temp

    print('''File name of sensor temperatures: {0}
Number of temperatures below {1}: {2}
Average Temperature: {3}
'''.format('temp.txt', temp, under, avg))

if __name__ == "__main__":
    main()
