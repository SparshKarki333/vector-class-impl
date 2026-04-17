# Custom C++ Vector Implementation

A high-performance, manual implementation of a dynamic array (`std::vector`) focusing on **Memory Management**, **RAII**, and **Move Semantics**. This project was built to master the fundamental C++ concepts required for low-latency systems and Quantitative Development.

## Key Features
- **RAII (Resource Acquisition Is Initialization):** Ensures deterministic memory cleanup via the Destructor.
- **The Rule of Five:** Complete implementation of Default/Parameterized Constructors, Copy/Move Constructors, and Copy/Move Assignment Operators.
- **Move Semantics:** Optimized for performance by transferring ownership of heap resources instead of performing expensive deep copies.
- **Automatic Growth:** Implements a doubling strategy for capacity reallocation during `push_back` operations.

## Build Instructions

This project uses **CMake**, the industry-standard build system for C++.

### Prerequisites
- A C++17 compatible compiler (GCC/Clang)
- CMake 3.10 or higher

### Building the Project
Follow these steps to compile the project from the root directory:

1. **Create a build directory:**
   ```bash
   mkdir build && cd build
   ```
2. Generate the build files and compile the source:
   ```bash
   cmake .. && make 
   ```
3. Run the program:
   ```bash
   ./vector
   ```
