Current compiler is close to C++ compiler with reduced functionality.

Types:
It supports numbers (decimal and real) and strings operations.
Numbers can be represented as decimal sequence of numbers (like 499, 949 etc.) or like real, separated with ONLY one DOT (like 5.2, 4.6). Commas are not used in real number presentation.

Variables creation:
To create variable, you should use system word "var".
Variable name can't contain any system character (described in bnf). All other chars are permited.
Variables exist only in their scope.

Loops:
All 3 typical loop types are implemented: for, do, do-while. Syntax the same as in C++.

Condition:
Common C++ if condition is implemented.

Function declaration:
To declare new function use system word "func" before function name. Also doesn't need to specify return type of func. Value of last command of function will be returned.
Don't specify type of parameters as well. Use ';' to separate parameters.
For now, function once created, exists always, despite scope.
Ex: 
func pow(x; n) 
{ 
	var res = 1;
	for (var i = 0; i < n; i = i + 1)
	{
		res = res * x;
	}
	res;
}

Function call:
Close to C++, but except of commas use ';' to separate variables;
Ex: pow(2; 5);

Standart output function:
You can use function out() with one parameter to output your value to file.
Use function cout() with one paramenter to print something to build console
The same time you can use function in() to input something from console. To type value of real variable from code, use ' before name. '<variable_name>
New standart function "print". First argument should be string or expression, that returns string. It`s format string, to insert your value use '%' character for any type of variable.
Ex:
//real code
var a = 10;
var s = in();
a = 0;
out(s);
//console input
'a
//output file 
10
//Really fancy feature

Ex of print:
//code
print("Hello, %. Your ID is %."; "Kostya", 1);
//output
Hello, Kostya. Your ID is 1. 

Line splitting:
Compilor doesn't care about ends of line, it reads code sequentually. So you can easily type 1 lexeme on one line.
You can't split lexeme.

Features of compiler:
Every expression can be computed as value.
That is why you can easily add two blocks of code, or loops, or conditions.
The same time in IF condition part you can use expression or in FOR declaration.
Ex:
var s = 11 * for (var a = 0; a < 5; a = a + 1)
{
	l = l 
	+ a * 2;
};
THIS IS VALID IN THIS LANGUAGE.

Code func:
You can use code() function, to insert into your code, code, written from console.
Code from console can use any variable, created in real code. I know, that it's unsafe, but it's funny.
To stop typing code from console use "end" command. ("end" should be the one word in line without any additional spaces or symbols).

Example of Hello world:
out("Hello, World!");

Example of Fibbonacci row:

//code
cout("Please, enter ending fibbonachi number");
var FIBB_END = in();
var el0 = 0;
var el1 = 1;
for (var i = 0; i < FIBB_END; i = i + 1)
{
	var temp = el0 + el1;
	el0 = el1;
	el1 = temp;
	print("Fibbonacci %, value %"; i + 1; el1);
}

//console
Please, enter ending fibbonachi number
15

//output
Fibbonacci 1, value 1
Fibbonacci 2, value 2
Fibbonacci 3, value 3
Fibbonacci 4, value 5
Fibbonacci 5, value 8
Fibbonacci 6, value 13
Fibbonacci 7, value 21
Fibbonacci 8, value 34
Fibbonacci 9, value 55
Fibbonacci 10, value 89
Fibbonacci 11, value 144
Fibbonacci 12, value 233
Fibbonacci 13, value 377
Fibbonacci 14, value 610
Fibbonacci 15, value 987

General compiler work.

As input compiler expect raw code lines. It doesn`t matter, as was written before, how you orginise splitting of lines, it can read one token on every line.
This compiler looks for tokens, that describes language. Every time it finds new, depends on token it tries to read other elements of expression. 
For example if compiler finds token "if" it does mean, that next meanable char (we skip tabs, spaces, new lines) should be open bracket '(' and after it should be expression. On this step compiler starts to read next expression recursively, and after successful reading of expression and finding closed bracket ')' compiler try to read next expression, that should form body of condition. After this compiler forms class object Condition, that contains that expressions as arguments and save it in list of commands.
So all work of compiler is finding tokens, reading needing expressions recursively and form structures, that are saved in list. This structures can contain all kinds of expressions as their argument, so Condition expression can contain condition expression as it`s condition. 
At the end compiler gets this list of commands and run them one by one, passing every command special structure, that is called Blackbox.
This blackbox contains input/output stream to communicate with user, list of avaliable variables and list of avaliable functions. structure is passed by reference, `cause during work size and filling of lists changes.
Also during compilation compiler saves line and row of every command to show meanable errors.

