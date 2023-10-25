#include <iostream>
#include <cstdlib>

int main() {
    // Create a memory leak by dynamically allocating memory
    int* memoryLeak = new int[10];
    
    // Not deallocating the allocated memory intentionally
    // delete[] memoryLeak; // Uncomment this line to fix the memory leak
    
    // Accessing the allocated memory to avoid optimizing it away
    for (int i = 0; i < 10; i++) {
        memoryLeak[i] = i;
    }
    
    // Display some output to show the program ran
    std::cout << "Program completed." << std::endl;
    
    return 0;
}

