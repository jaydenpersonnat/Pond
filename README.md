# Pond

Pond is a high-level interpreted programming language written in C
with Flex and Bison. Currently, it has support for variables, basic data types, 
lists, several arithmetic and logical operators, functions, conditionals, and loops. 

Pond is a language where code is written in a sequence of statements each seperated by a 
semicolon (with an optional last semicolon). 

Under the current version, all the variables declared in Pond are globally scoped 
with the exception of variables defined in a function header. 

Look at the mario.pond and fizzbuzz.pond files in the examples folder for some
classic problems that can be solved in Pond!

### Variables 
The language supports the following data types: 
    1. Integers 
    2. Floats 
    3. Booleans
    4. Strings 

Variable assignment follows a Python-syntax where typing is implicit. 

Examples are shown below:
```
x = 5; 
name = "John Doe"; 
bool1 = TRUE; 
bool2 = FALSE; 
pi = 3.14159; 
```

#### PRINT
The language has three built-in functions to print a value (print, printn, and prints). 
print and printn (stands for "print newline") are synonymous and print a newline at the end of each line. 
prints("print sameline") does not add a newline at the end of the statement. 
```
print(name); 
"John Doe"
% 


print(bool1);
TRUE 
%

prints(pi);
3.14159%

printn(6);
6 
%
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
   9. Equal (== | equals) and not equal (!=) for integers
   10. Greater Than (>) for integers
   11. Less Than (<) for integers
   12. Less Than or Equal To (<=) for integers
   13. Greater Than or Equal to (>=) for integers 
   14. The NOT (not) for bools 
   15. AND (and | AND) and OR (or | OR) for bools 
   16. String concatenation (sjoin | &) for strings 
   17. List concatenation (ljoin | @) for lists 
   

```
 x = 5;
 y = 3;

print(x + y);
8

print(x - y);
2

print(x * y);
15

print(20 / 5);
4

print(122 % 5); 
2 

print(x ^ y);
125

print(|-20|);
20

print(5!);
120

print(5 == 5);
TRUE 

print("hello " sjoin "world");
"hello world"
```

#### IF 
If statements will execute a block of code if a condition is true. Just like in other programming 
languages, Pond supports else if and else statements. 

```
x = 10; 
if (x > 5)
{
    print(TRUE); 
};

x = 5;
if (x == 5)
{
    print("yes");
}
else if (x == 20)
{
    print("no");
}
else
{
    print("nothing");
}

```

#### Loops 
The language has support for the following loops (for, while, and "do"). 

##### Do Loops 
Do loops take a number and then execute the code block inside
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
to a certain value. The incrementation is specified after a "incr" or "add" keyword. 

```
for i = 1 to 20 incr 1
{
    print(42); 
};

for i = 0 to 30 add 5
{
    print(i); 
}

```

The first loop prints the number 42 twenty times while the second will print out
the multiples of 5 from 0 to 30. 

# stop and break 
As the name suggests these keywords when used will stop the evaluation of a sequence of code.
These can be used to stop the entire program and break from loops. 

```
x = 5;
y = 3;
print(x);
stop; 
print(y);

5

```

##### Lists 
Like in many programming languages, lists are a collection of items in Pond. 
Under the current implementation, lists can contain elements of different types, 
and can be indexed into via {} syntax but are not mutable. Strings can also be indexed into 
to obtain a character. 

```
names = ["John", "Jack", "Jill"]; 
print(names{0});
John

print(names{1});
Jack

print(names{2});
Jill

name = "Jayden";
print(name{2});
y
```

##### Functions 
Functions in Pond take in arguments and return an output specificed by a "return"
or "output" keyword. 

A function is declared by a function name and then takes arguments as comma seperated 
values. 

Calling a function is similar to other programming languages, by specifying a function name
and a passing in arguments as comma seperated values. 

```
sum(x, y)
{
    output x + y; 
}; 

result = sum(3, 6);
print(result);

factorial(x)
{
    if (x equals 0)
    {
        return 1; 
    }
    else
    {
        return x * factorial(x - 1);
    }
};
print(factorial(6)); 
```

#### Limitations 
As an early-stage language, Pond has a few limitations that are to be resolved in the 
future:
1. the current type-checking and error handling is weak, which could lead to undefined behavior 
2. lack of escape characters such as \n and \t 
3. lack of polymorphism for built-in operators 
4. getstring function does not handle whitespace 

#### What's Next?
- Comments 
- more rigorous type checking and descriptive error messaging 
- built-in list and string methods 
- classes and OOP 
- user defined types 
- libraries and import 
- VSCode extension of syntax and semantic highlighting 

##### Running? 
```
clone the repository 

make pond
./pond [filename].pond

```