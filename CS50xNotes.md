# CS50x Notes

* Syllabus: https://cs50.harvard.edu/x/2020/syllabus/
* Course link: https://www.edx.org/course/cs50s-introduction-to-computer-science
* Professors: David J Malan, Brian Yu, Doug Lloyd

## Timeline summary
|      WEEK     | DATE STARTED | DATE COMPLETED (PSET) |
|:-------------:|:------------:|:---------------------:|
|       0       |  18/09/2020  |       19/09/2020      |
|       1       |  19/09/2020  |       26/09/2020      |
|       2       |  26/09/2020  |                       |
|       3       |              |                       |
|       4       |              |                       |
|       5       |              |                       |
|       6       |              |                       |
|       7       |              |                       |
| FINAL PROJECT |              |                       |
|      EXIT     |              |                       |

## Week 0: 18/09/2020
- Input => Algorithm => Output
- Functions, Loop, Conditions, Boolean expressions, Variables, Threads, Events...
- Algorithm efficiency: n, n/2, log(n)
- Numbers, Characters, Images, Video, Sound can be representd in binary
- ASCII, Unicode
- Decimal, Binary: base 10 and base 2
- 8 bit can represent 256 character maxium. Max value = 255
- Color in RGB: 0 --> 255
- Coding with Scratch: a graphical programming language: https://scratch.mit.edu
- **PSET0 submission date:** 19/09/2020
- PSET link: https://scratch.mit.edu/projects/427216291

## Week 1 - C: 19/09/2020
- Using of CS50 IDE, Sandbox
- stdio.h, cs50.h
- Data types: char, int, float, long, bool,...-
- Placeholders: %i, %s, %f, %c, %li
- Basic navigation using command lines: cd, ls, mkdir, rm, rmdir (delete folder), mv (rename or move folder)
- C code need to use compiler to translate code to machine code (aka binary)
- "clang <file>"
- "clang -o <name> <file-name>" so that I can run the code with easy name
- cs50.h library: get_char, get_double, get_float, get_int, get_long, get_long_long, get_string
- When writing a function, pay attention to semicolon, indentation
- help50.h : libarary, like a training wheel to help troubleshoot the problems
- There are some functions are created to solve many common problems and they're put in a so-called library, like cs50.h or stdio.h. Library is a collection of hard-coding works someone wrote for you in the past
- Code in C need compiler bcz it's old language, people in the past was less care about user-friendliness, care more about performance,...
- help50 make hello: to see a human-friendly message, what's your error. E.g: help50 make hello
- style50 hello.c: (including file name) to check styling of the code
- check50: check the correctness of the code. Eg: check50 cs50/problems/hello
- integer in C (get_int) is only 32-bit, it count up to 4bn, but it accept up to 2bn number bcz it include negative numbers, ie: -2bn (still total 4bn)
- get_long in cs50.h is in 64-bit
- In C, use only single quote when do comparision (if, else if)
- Pay attention to code design or style
- Abstraction is simplication of a complicated problem (function)
- Put custom function at the end in the code (details of function, explain what it does), put THE NAME OF that function at the top aka prototype (to let the machine now a function is define), and what a function do in between them. The code wouldn't run if they have different order.
- Int take up 4 bytes (32 bit), char - 1 byte (8bits), float - 4 bytes, double (float x2) - 8 bytes (64bits of data)
- If I want to use boolean data type, I need to do #include <cs50.h> as heading
- int x = (bool_ex) ? 5 : 6; ==> Quick conditional expression. Only use for quick decision. if bool_ex is true, go to either 5 or 6. First position true, second is false
- "switch" statement for discrete cases (many cases??) to make decision, use with "break" and "default" (check switch_cond.c in this repo)
- Command line: To copy entire directory and files: cp -r old_dir new_dir/ -r for recursive
- rm -f file: delete file without asking question
- rm -r folder or rm -rf folder (without asking question)
- **PSET1 submission date**: hello - 22/9, mario (less/more) - 23/9, cash - 24/9, credit - 26/9

## Week 2 - Array: 26/09/2020
