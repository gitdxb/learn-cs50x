# Write your code here :-)
from time import sleep

n = 40600001
while n > 1:

    digit = int((n % 100) / 10)
    n = int(n / 100)
    print(digit)
    sleep(1)