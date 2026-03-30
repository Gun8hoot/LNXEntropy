<div align="center">
    <img src=".images/lnxentropy.png">
</div>

<h2>STILL IN BUILD</h2>

## Description:
LNXEntropy is a library contain function that can add randomness to a pseudo-generated number. Root privileges are required to read data from /dev/input/. I will probably develop compatibility with x11 and Wayland to avoid root obligation

## Instruction:
1. Build the project using `make` 
```sh
make
```
2. Add `lnxentropy.so` during the compilation of your object files
```sh
gcc {your_compilation_flag} -L. -llnxentropy -c -o {yourfile}
```
- Remove every compilation object file
```sh
make clean
```
- Remove every compilation object file and remove the compiled file
```sh
make fclean
```
- Remove every compilation object file, remove the compiled file and rebuild the project
```sh
make re
```

## Documentations
- `pid_t lnxentropy_init(void)`: Initialization function, create a subprocess and every thread for every mouse and keyboard devices founded.
- `uint32_t lnxentropy_recov(uint64_t min, uint64_t max)`: Take the number on the pipe which is get from every threads
- `bool lnxentropy_exit(pid_t pid)`: Kill the subprocess and his threads. You can manually kill the process 

### Errno error codes
**`EROOT`** - Need root permission to read files on /dev/input/by-path.
**`EALLOC`** - A memory allocation failed.
**`EOPEN`** - Failed to open devices files.
