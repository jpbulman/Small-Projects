class Math:
 x = 1
 a,b =3,4

 mylist = [3,2,3]
 mylist.append(4)

 print(mylist + [5, 6, 7])

 print(mylist[0])

 print(mylist[3])

 remainder = 11%6 #5

 print(2**4) #16

 manyhellos = (10 * ("hello!" + " "))

 print(manyhellos)

 print(4 * mylist)

 if x == 1:
     print(x)

     name = "Joe"

     age = 256

 print("He is %s and he is %s years old" % (name, age))

length1 = len("greetings")

cond1 = 1==2

print(cond1)

num1 = 256
twolist = [2,4,8,16,32,64,128,256,512,1024,2048]

if num1 in twolist:
    (print("yes"))
else:print("no")

islist1 = [1,2,5]
islist2 = [1,2,5]

(print(islist1 is islist2))
(print(1 is 1))





def factorial(num1):
    if num1 == 1:
        return 1
    else: return (num1 * factorial(num1-1))

print(factorial(12))

def collatz(number):
    if number==1:
        return print("Yes, the number fits the theorem")
    elif number%2==0:
        collatz(number/2)
    else:collatz((3*number)+1)

collatz(123)




