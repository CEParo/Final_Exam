import sys

def main():
    temp = eval(sys.argv[1])
    file = open('temp.txt', 'r')

    total = 0;
    below = 0; 
    temps= 0;
    for line in file.read().split('\n')[2:-1]:
        temps += 1
        total += eval(line)
        if eval(line) < temp:
            below += 1

    avg=Sum/Temp

    print('''File name of sensor temperatures: {0}
Number of temperatures below {1}: {2}
Average Temperature: {3}
'''.format('temp.txt', temp, below, avg))

if __name__ == "__main__":
    main()
