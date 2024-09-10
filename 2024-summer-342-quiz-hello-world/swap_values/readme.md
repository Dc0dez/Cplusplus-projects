## How to run

### Option 1: Compile and link in one command to generate the executables

```bash
g++ swap_value.cpp util.cpp
```

### Option 2: Compile first into object files, and then link object files into executables

```bash
g++ -c util.cpp -o util.o # compiling
g++ -c swap_value.cpp swap_value.o # compiling
g++ swap_value.o util.o -o a.x # linking
```
