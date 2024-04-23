# Sorting integers with C++ 23

This program compares heap, bubble and select sort algorithms durations by applying them in order to sort a sequence of random integers. Each sorting algoritm runs on its own array (each array stores the same sequence of integers) in a separate thread.
After all sorting algorithms are executed the program shows the duration of each sorting algorithm in seconds.

## Usage
To use this program, simply compile and run the executable.

### Compile

#### With CMake

cd to the project dir and run
```
cmake .
make
```

#### Directly with g++
`g++ generator.cc -std=c++23 -O3 -o sort`

#### Directly with clang++
`clang++ generator.cc -std=c++23 -O3 -o sort`

## Launch
After compiling, execute the program by running the generated executable:
`./sort`

## Configuration

Configuration is performed in the header file `config.h` by directly editing the corresponding constants.

In order for the changes to take effect, you need to recompile the program.