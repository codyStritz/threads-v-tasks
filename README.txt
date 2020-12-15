README
--------------

Baseline (case1):
	
	Compile case1.c as usual.
	When running case1, pass a command line argument to declare n (where calculating the sum
	from 0 to n). 
	
	Example: ./case1 100000000
	
Multithreading (case2):

	Open case2.c in text editor and set values of macros N and NUM_THREADS to desired values

	If running a linux system, make sure to pass -pthread while compiling case2.c
	
	Example: gcc -pthread case2.c -o case2
	
	Run case2 as usual
	
Multitasking (case3 and mtask):

	Before running case3, BOTH case3.c and mtask.c must be compiled. Compile as usual.
	
	Once both case3.c and mtask.c have been compiled, run case3 as usual and pass two
	command line arguments: N and NUM_TASKS
	
	Example: ./case3 100000000 4

	
