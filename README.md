# Pond

High Level Programming Language in C 

The language is currently in it a very early stage and the documentation below 
serves as a preview for what's to come, but has support for the following:


### Variables 
The language supports the following data types: 
    1. Integers 
    2. Floats 
    3. Booleans
    4. Strings 

Defining follows a python-like syntax with the following format: ```[variablename] = [value];```
Examples are shown below:
```
x = 5; 
name = "John Doe"; 
bool1 = TRUE; 
bool2 = FALSE; 
pi = 3.14159; 
```

#### PRINT
Just like in Python, the print function will take in an argument and output it to the terminal. 

```
print(name); 
> "John Doe";

print(bool1);
> TRUE 

print(pi);
> 3.14159; 

print(6);
> 6; 
```

#### Operators 
The following operators are supported (so far) in Pond:
   1. Addition (+) of integers and floats 
   2. Subtraction (-) for integers
   3. Multiplication (*) for integers
   4. Division (/) for integers
   5. Modulo (%) for integers 
   6. Exponentiation (^) for integers 
   7. Absolute Value (||) for integers
   8. Factorial (!) for integers
   9. Equal (==) for integers
   10. Greater Than (>=) for integers
   11. Less Than (<=) for integers

```
 x = 5;
 y = 3;

 print(x + y);
 > 8
 print(x - y);
 > 2
 print(x * y);
 > 15
 print(20 / 5);
 > 4
 print(122 % 5); 
 > 2 
 print(x ^ y);
 > 125

 print(|-20|);
 > 20

 print(5!);
 > 120; 

 print(5 == 5);
 > TRUE 
```

#### IF 
if statements will execute a block of code if a condition is true
```
x = 10; 
if x > 5
{
    print(TRUE); 
}

```

#### Loops 
So far, the language has simple support for the following loops (for, while, and "do")
where values can be printed repeatedly 

##### Do Loops 
Do loops are loops that will take a number and then execute the code block inside
the loop repeatedly based on the number. 
```
do 5
{
    print(42);
}
> 42
> 42
> 42
> 42 
> 42 

x = 4; 
do 3
{
    print(x!);
}
> 24
> 24 
> 24 

```


##### While Loops 
While loops in Pond, like in all programming languages, take in a condition and then 
execute the code block inside the loop along as the condition is true. 

```
x = 10; 
while x > 5
{
    print(x); 
}
```
The above code block will result in an infinite loop. 

##### For loops 
For loops in pond initialize a variable to a integer and then increments that integer
to a certain value. The incrementation is specified after the "incr" keyword. 

```
for i = 1 to i = 20 incr 1
{
    print(20); 
}
```

The above loop prints the number 20 a total of 20 times. 


#### What's Next?
- support for binary operators such as AND, OR, and FLOAT Arithmetic 
- more sophisticated loop and conditional logic allowing multiple statements in a single block
- User-defined function support 


##### Running? 
A requirements.txt file will be added in the future but to run the program:
```
make pond
./pond [filename].pond

```