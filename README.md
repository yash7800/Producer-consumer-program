Multithreaded Producer-Consumer Simulation
Project Overview
This project simulates the Producer-Consumer problem using multithreading. The program creates two threads: a Producer thread that generates items and places them into a shared buffer, and a Consumer thread that retrieves and processes items from the buffer. Synchronization between threads is managed through mutexes and condition variables to prevent race conditions and ensure thread safety.

Key Features
Producer Thread: Continuously generates items and places them in a shared buffer.
Consumer Thread: Continuously consumes items from the buffer.
Thread Synchronization: Mutexes and condition variables are used to ensure proper coordination between the producer and consumer.
Bounded Buffer: The buffer has a fixed size, and both threads handle situations when it is full or empty.
Fixed Iterations: The program runs for a set number of iterations (default is 10) to prevent an infinite loop.
Requirements
A C++ compiler that supports C++11 or later.
POSIX threads (pthreads) support for Linux/macOS systems.
For Windows users: The program uses Windows-specific threading functions (Windows.h).
Compilation and Execution
On Linux/macOS:
Compile the program:

bash
Copy
Edit
g++ -o producer_consumer producer_consumer.cpp -lpthread
Run the program:

bash
Copy
Edit
./producer_consumer
On Windows:
Use a C++ compiler like MinGW or Visual Studio that supports Windows threading functions.
Program Flow
1. Producer Thread
The Producer generates items and places them into the buffer.
If the buffer is full, the Producer waits until space is available.
2. Consumer Thread
The Consumer consumes items from the buffer.
If the buffer is empty, the Consumer waits until an item is produced.
3. Synchronization
Mutexes: These are used to ensure that only one thread accesses the buffer at a time.
Condition Variables: These are used to pause threads (Producer or Consumer) until certain conditions are met, such as the buffer being empty or full.
4. Program Termination
The program runs for a defined number of iterations (default: 10) to prevent continuous execution.
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
producer_consumer.cpp: Contains the main source code for the program.
