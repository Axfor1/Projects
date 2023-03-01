from cs50 import get_float

ch = 0
co = 0


while ch <= 0:
    ch = get_float("Change owed: ")
    cents = round(ch * 100)

# While cents is greater than 0, take away largest coin possible  and increment count
while cents > 0:
    if cents >= 25:
        cents = cents - 25
        co = co + 1
    elif cents >= 10:
        cents = cents - 10
        co = co + 1
    elif cents >= 5:
        cents = cents - 5
        co = co + 1
    elif cents >= 1:
        cents = cents - 1
        co = co + 1

print(co)