import sys

temp = eval(sys.argv[1])
file = open('sensor_temp.txt','r')

total=0;
temps=0;
below=0;
for line in file.read().split('\n')[2:-1]:
    temps += 1
    total += eval(line)
    if eval(line) < temp:
        below+=1


avg = total/temps


print("Number of temperatures below {0} degrees Celsius:{1}".format(temp, below))
print("Average temperature:{0}".format(avg))
    
    
