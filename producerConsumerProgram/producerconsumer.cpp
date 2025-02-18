#include <iostream>
#include <queue>
#include <windows.h>  // Windows-specific thread library

using namespace std;

// Shared buffer and synchronization primitives
queue<int> buffer;
const int BUFFER_SIZE = 5;  // Maximum buffer size
HANDLE mutex_lock;
HANDLE cond_producer;
HANDLE cond_consumer;
const int MAX_ITERATIONS = 10;  // Limit the number of iterations

// Function for the Producer
DWORD WINAPI producer(LPVOID lpParam) {
    int item = 0;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        Sleep(1000);  // Simulate production time

        WaitForSingleObject(mutex_lock, INFINITE);  // Lock mutex

        // Wait if the buffer is full
        while (buffer.size() == BUFFER_SIZE) {
            cout << "Producer waiting - Buffer is full\n";
            ReleaseMutex(mutex_lock); // Release mutex before waiting
            Sleep(1000); // Wait time before retrying
            WaitForSingleObject(mutex_lock, INFINITE); // Lock mutex again
        }

        // Produce an item
        item++;
        buffer.push(item);
        cout << "Producer produced: " << item << "\n";
        iterations++;

        // Signal the consumer and unlock the mutex
        SetEvent(cond_consumer);
        ReleaseMutex(mutex_lock);
    }
    return 0;
}

// Function for the Consumer
DWORD WINAPI consumer(LPVOID lpParam) {
    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        Sleep(2000);  // Simulate consumption time

        WaitForSingleObject(mutex_lock, INFINITE);  // Lock mutex

        // Wait if the buffer is empty
        while (buffer.empty()) {
            cout << "Consumer waiting - Buffer is empty\n";
            ReleaseMutex(mutex_lock);  // Release mutex before waiting
            Sleep(1000); // Wait time before retrying
            WaitForSingleObject(mutex_lock, INFINITE);  // Lock mutex again
        }

        // Consume an item
        int item = buffer.front();
        buffer.pop();
        cout << "Consumer consumed: " << item << "\n";
        iterations++;

        // Signal the producer and unlock the mutex
        SetEvent(cond_producer);
        ReleaseMutex(mutex_lock);
    }
    return 0;
}

int main() {
    // Initialize synchronization primitives
    mutex_lock = CreateMutex(NULL, FALSE, NULL);
    cond_producer = CreateEvent(NULL, FALSE, TRUE, NULL); // Signaled by default
    cond_consumer = CreateEvent(NULL, FALSE, FALSE, NULL); // Not signaled by default

    // Create producer and consumer threads
    HANDLE producer_thread = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    HANDLE consumer_thread = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    // Wait for threads to finish
    WaitForSingleObject(producer_thread, INFINITE);
    WaitForSingleObject(consumer_thread, INFINITE);

    // Close synchronization handles
    CloseHandle(mutex_lock);
    CloseHandle(cond_producer);
    CloseHandle(cond_consumer);

    return 0;
}
