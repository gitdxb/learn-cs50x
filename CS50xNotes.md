# CS50x Notes

* Syllabus: https://cs50.harvard.edu/x/2020/syllabus/
* Course link: https://www.edx.org/course/cs50s-introduction-to-computer-science
* Manual pages: https://manual.cs50.io/
* CS50 IDE: https://ide.cs50.io/
* Professors: David J Malan, Brian Yu, Doug Lloyd

## Timeline summary
|      WEEK     | DATE STARTED | DATE COMPLETED (PSET) |
|:-------------:|:------------:|:---------------------:|
|       0       |  18/09/2020  |       19/09/2020      |
|       1       |  19/09/2020  |       26/09/2020      |
|       2       |  26/09/2020  |       29/09/2020      |
|       3       |  29/09/2020  |       04/10/2020      |
|       4       |  05/10/2020  |                       |
|       5       |              |                       |
|       6       |              |                       |
|       7       |              |                       |
| 	8       |              |                       |
| FINAL PROJECT |              |                       |

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

## Week 2 - Arrays: 26/09/2020
- "clang" is the compiler, "make" does all the clang's dirty works for us
- Compiling source code into machine code include 4 steps: preprocessing, compiling, assembling, linking
- Preprocessing: the 1st process that read all the headings, start with #: stdio.h, cs50.h...
- Compiling: souce code in C ==> Assembly code 
- Assembling: assemble Assembly codes into binary instruction so CPU can understand
- Linking: combining library (headings) with our source code to make 1 file that can run (ie: a.out , ./hello,...)
- Data types: bool - 1 byte, char - 1 byte,...
- We use "const", to tell compiler that value of N (length of array) should never be changed. 
- String is array of characters, usually end with "\0" after every string, it costs 1 byte, where all 8 bits set to zero. It's called null character
- String initiated with "string ...", i.e: "string names[4]"
- <string.h> is the library for string, strlen() is method to cal the length of string, %lu is its placeholder
- To convert a char to lower or upper case, loop through each char and +32 or -32.
- <ctype.h> is a libraby do that dirty job, simply use tolower() or toupper() to convert
- See more: https://manual.cs50.io/
- Google more about Command Line argument
- To see ASCII code associated with character, when printf put placeholder %i instead of %c, each character need to be printed individualy
- int array[] = {1,2,3...}; to simplify an array, odmit the array length
- To copy array items to another list, loop through each item and assign them to a new array
- PSET2 submission date: readability - 28/9, ceasar - 29/09

## Week 3 - Algorithms: 29/09/2020
- Tough week! Let's go!
- Big O notation: "on the order of...", upper bound of number of steps, or the worst case, and typically what we care about more
- Common running times: O(n^2), O(n log n), O(n) - linear search, O(log n) - binary search, O(1)
- Big Ω, big Omega notation, lower bound of number of steps for our algorithm
- For big O, linear search: worst case is n, best case is 1 (bcz it might take only 1 step to find the number)
- "strcmp" in <string.h> compare 2 strings, bcz in C you can't do it easily: strcmp(str1, st2) == 0, if you want to search if there is the same string exists
- You can make custome data type, i.e: person. typedef struct {...}
- Bubble sort - O(n^2): compare adjacent pair in a list, n - 1 times, n - 2 pairs. Biggest number get sorted and stay in the most right position
- Selection sort - O(n^2): Find the smallest number put in the most left, find the next smallest put second left, so on and so forth, this sort still look for each element in the list to find the smallest
- Recursion: use its own method to solve its problem
- Merge sort: the best and the worst case take the same number of step, therefore: it has Θ(n log n), aka Theta Notation
- Worst case list:
1. O(n2): bubble sort, selection sort, insertion sort
2. O(n log n): merge sort
3. O(n): linear search
4. O(log n): binary search
5. O(1): nothing

- Best case runtime algorithm:
1. Ω(n2): selection sort
2. Ω(n log n): merge sort
3. Ω(n): bubble sort, insertion sort
4. Ω(log n): nothing
5. Ω(1): linear search, binary search
- O(n) and O(n^2) is almost the same in effiency, so it's all O(n)
- O(log2n) can be the same as, and called O(log n)
- The worst case = maximum steps, the best case = the minimum steps to solve the problem
- Computer "return 0" if it execute correctly, " return 1 or any number" if it doesn't
- If an array is declared, the compiler need to know the length and data type
- Creating custom data type is encapsulation feature of C, put all related info in 1 place (good design), and thing like array when we make a few different arrays with too many items, at some scale it become bad design. 
- Lots of company store lot of accounts, passwords, history...many pieces of data associated with me will be better design with custom data type. ie: people[].names, people[].number...
- If you wanna get custom array with custom length by asking input from user, you should try to use constant, i.e: const int NUMBER = 10; so we have the length to loop through it, this const stay outside main()
- Recursion is a concept that you can do things again and again without using a loop, an elegant solution
- Merge sort: Base case: if only one number - quit, recursive case (func call itself): SORT left, SORT right...merge sorted
- Bubble sort: the concept is to move the biggest number to the right, sort from right to left, the worst case scenario is when it's in reversed order, biggest on the left and so on,best case is when everything is sorted
- Selection sort: building sorted array from left to right, smallest items to the left
- For binary search, items need to be SORTED (!important) before the search
- Bubble sort: set counter to non-zero value, loop through each item until counter = 0, otherwise add 1 to each swap.
- Insertion sort: very fast, start with first element become a sorted portion, for the next unsorted elements, the next each item insert into sorted portion with sorted position, no need to go back and forth for each time sorting, each element get scanned once and get sorted immediately. Worst case is when all element sorted in reversed order, best case is when everything is sorted by luck
- PSET submission date: Plurality - 2/10, Runoff - 4/10

## Week 4 - Memory: 05/10/2020
- The addresses for memory use the counting system: hexadecimal (16 digits, 0-9, A-F)
- Recall 8 bits can count up to 255
- Hexadecimal can represent 255 in only 2 digits
- The max value: 255, can be represented in FF ( F - 16^0. F - 16^1)
- F is value of 15 in decimal, so 16^1 * 15 = 240, 16^0 * 15 = 15. Total of 255
- 0A is the same as 10, 0f = 16,...there is no case sensitivity
- RGB color system also use hex, i.e 000000 means black
- 0x10 , the 0x is prefix, 0x10 = 16
- So Hex can be used to access any data type in the memory, the address will start with something look like this: 0x12345678, the address is called pointer
- In C, to locate that address, we use & operator, %p is the placeholder. ie: printf("%p\n", &n); to access var n in the memory
- "&" means: " Get the address of this value", "&n" - the address of n
- Pointer: start with * operator, meaning go to the location that a pointer is pointing to
- A pointer will be 8 bytes, double an integer
- "*&n": go the the address of n, print out the value

1. printf("%p\n", &n) - print address where n is stored
2. printf("%i or %c\n", *&n) - print the value of that address
3. int *p = &n - assign the value in that address to a new variable, then printf("%p\n", p) - output the address (same with n), or printf("%i\n", *p) - output value of address

- "char *" is alias of "string" in cs50 library (training wheel lib), but more user-friendly, when "char *s = get_string("...") - it will get char by char
- <string.h>: copy string with "strcpy(str2, str1), without using a loop 
- malloc() in <stdlib.h> to allocate new memory when you try to copy a string (with loop)
- When copy a string to a new string, you need <string.h> to use strlen() and + 1 to it for the loop, to add null aka "\0" character, otherwise the memory will be run out of memory because it doesnt know where to stop. therefore computer crashes, program go to unknown area of memory
- Sometimes, the computer or mobile get slow, lagging because we open so many programs, apps, softwares, web browser tabs... it cause memory leak, or those things keep asking for new memory to run, it exhaustes the computer...
- When using malloc(), need to free memory after use, otherwise there is memory leak: bad! use free(str2), check leak by: help50 valgrind ./cp_str1. Shouldn't use free() more than 1
- When using malloc(), need to check if it gives back value NULL, if NULL don't do it otherwise "seg fault"
- The CS50 Library has been freeing memory it’s allocated in get_string, when our program finishes!
- Swapping 2 integer is like swapping 2 cups of water, you need 1 more empty cup to temporarily keep water, likewise integer, you will need a temp variable
- Swapping in C, you need to swap 2 original value not make the copy values and swap them. So you need a pointer to literally point to arguments, and you need to pass 2 addresses as arguments to swap()
- Memory Layout: From top to bottom: Machine code => Globals (global vars) => Heap (empty area, malloc() can get access to) => Stack (Where our func runs)
- If we call malloc() too many times, it goes past the heap and make heap overflow (aka: buffer overflow)
- If too many funcs called, we will have stack overflow, because stack has too many frams of memory allocated as well (aka: buffer overflow, too, entire computer might crash)
- scanf(): takes a format, %i, so the input is “scanned” for that format, and the address in memory where we want that input to go.
- For "string" with scanf(), you don't have to give it a "&" in formart
- ie: scanf("%d", &n) - go th address of n, assign format %d to n
- Declare a pointer: <data type> *<pointer name>
- Initialize pointer: <pointer name> = <address start with & operator>
- https://nguyenvanhieu.vn/ngan-xep-stack/
- https://nguyenvanhieu.vn/khoa-hoc-lap-trinh-c/
- http://diendan.congdongcviet.com/threads/t42977::tim-hieu-ban-chat-cua-con-tro-tu-co-ban-den-nang-cao.cpp
- Pointers (pointer variables) are special variables that are used to store addresses rather than values. (programiz.com/c-programming/c-pointers)
- Before, without the pointers, functions get passed in value, which is a copy of variable. But with pointers, we pass actual vars, that might change the whole original func, recall the toupper() when copy 2 strings
- When we work with data in hard disk, the data can't be manipulated directly there, need to pass to RAM and work from it. (watch SHORT: pointer)
- A POINTER IS NOTHING MORE THAN JUST ADDRESS - DOUG LLOUD
- Imagine working with pointer is like you give someone your notebook and ask him to update it, without making extra copy, check, update and give back to you to make update on your original notebook.
- So once you get the address of a var, go directly there and work with it
- NULL pointer is a pointer you don't set value immediately, better than it being set to random, garbage value by computer. Use "==" to if NULL exists. Once set pointer to NULL, the var doesn't randomly access random memory address that can do damage to your computer or other funcs
- When deference a NULL value ( with *), you will get Segmentation fault, which is a good thing, explained above
- int* p: meaning when you go to address of p, you will find there an integer. It's not itself an integer
- string (in <cs50.h>) or any pointers data type (int*, char*, float*...) usualy 4 or 8 bytes size ( depends 32 or 64-bits systems, where memory is 32 or 64 bits long)
- Recursive funcs are not always good, if there are too many recusive funcs are being called, it can cause stack overflow. A efficient solutions always have trade-off
- Whenever you set a var name and value, it belong to memory area of STACK (statically memory allocated), and dynamic memory allocated or var doesn't have a name usually belong to pool of memory called HEAP
- File manipulation in C, all funcs stay in stdio.h: fopen(), fclose(), fgetc(), fputc(), fread(), fwrite(), fprintf()
- FILE is a new data type, FILE *file pointer
- fopen() and fclose(), when working with file whether "r" or "w","a" mode, you can do only 1 mode/thing at a time, after every time you work with file, you need to close it with fclose()
- fgetc() to read each char in the file, only work when you set "r" mode <br/>
Code:<br/>
`char ch<br/>
while((ch = fgetc(ptr)) != EOF) //ptr is file pointer<br/>
    printf("%c", ch);`<br/>
- fputc() to write something to the file, only work when file in "w" or "a" mode, otherwise: error<br/>
Code:<br/>
`char ch
while((ch = fgetc(ptr) != EOF)
    fputc(ch, ptr2); // ch is char we get from ptr file to cp to ptr2`<br/>
- fread(<buffer>, <size>, <qty>, <file pointer>): read <qty> unit of <size> from the file pointer, and store them in memory in a <buffer>, only work when file in "r" mode:
e.g:  `fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);` or `fread(image[i], sizeof(RGBTRIPLE), width, inptr);` (from `filer` PSET)
e.g: `int arr[10]
      fread(arr, sizeof(int), 10, ptr` => read 40 bytes of int from `ptr` and store them to `arr` array
- 