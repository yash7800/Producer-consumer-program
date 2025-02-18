Multithreaded Producer-Consumer Simulation
Project Overview
This program simulates the Producer-Consumer problem using multithreading. It utilizes POSIX threads (pthreads) to manage two separate threads: one for the Producer and one for the Consumer. The Producer generates items and adds them to a shared buffer, while the Consumer retrieves and processes items from the buffer. Synchronization is ensured through the use of mutexes and condition variables.

Key Features
The Producer generates items and places them in a shared buffer.
The Consumer removes items from the buffer and processes them.
Thread synchronization is implemented using mutexes and condition variables to prevent data race conditions.
The program is configured to run for a predefined number of iterations (10 by default) to avoid infinite loops.
Requirements
A C++ compiler supporting C++11 or newer.
POSIX threads (pthreads) support (for Unix-like systems).
Windows users: Windows-specific threading mechanisms are used (Windows.h).
Compilation and Execution
On Linux/macOS:
Compile the program with the following command:
bash
Copy
Edit
g++ -o producer_consumer producer_consumer.cpp -lpthread
Execute the compiled program:
bash
Copy
Edit
./producer_consumer
On Windows:
Use a C++ compiler, such as MinGW or Visual Studio, that supports Windows threading functions.
Program Workflow
The Producer thread continuously produces items and places them in a shared buffer.
The Consumer thread removes and processes items from the buffer.
Mutexes ensure that only one thread can access the buffer at any given time, while condition variables enable the threads to wait for specific conditions (like when the buffer is full or empty).
The program stops after a defined number of iterations (default 10) to avoid running indefinitely.
Sample Output
plaintext
Copy
Edit
Producer produced: 1
Consumer consumed: 1
Producer produced: 2
Consumer consumed: 2
...
File Structure
producer_consumer.cpp: The main source code for the program.
