# ARM-Disassembler
C++ Project to create an ARM disassembler capable of loading an executable on Raspberry pi and disassembling it.

read.cc - reads in a .out file and prints the hex for the input instructions
    g++ read.cc -o read.out
    ./read.out test.out
    where test.out is the file being parsesd