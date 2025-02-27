# For macOS with M1 chip

### Clang is a built in C compiler, alternative to gcc

#### compile C file into executable file

clang fileName.c -o outputExecutableFile

#### run executable file

./executableFile

#### measure time the execution time

time ./executableFile

# If you want to learn pure, standard C (without compiler-specific extensions), GCC is the best option. Why?

### 1. ✅ Strict Adherence to the C Standard - GCC fully supports ANSI C (C89), C99, C11, and C17.

### 2. ✅ Cross-Platform & Open Source - Works on Linux, Windows (via MinGW), macOS, and even embedded systems. Many real-world applications and open-source projects are built with GCC.

### 3. ✅ Better Error Checking for "Real C" - Forces you to write portable and correct C code.

### 4. ✅ Industry Standard for Systems Programming - The Linux kernel, GNU utilities, and embedded systems all use GCC.

### 5. ✅ Clang adds modern safety checks not found in GCC. Used for macOS/iOS development

### ----------------------------------------------------------------------------------------------

### ----------------------------------------------------------------------------------------------

### ----------------------------------------------------------------------------------------------

# Since on my MAC gcc refers to clang, I will use "gcc-14 fileName.c -o execFile" to compile C code, but gcc-14 will compile C code to assembly code, but Clang's assembler(as) is converting it to machine code. The final linking step(collec2) is using -lSystem which is macOS’s default system library (libSystem.B.dylib).

# ✅ How to Get True Linux-Like Compilation on macOS M1? (diffentianting between M1 and Intel CPU is important)

# Use a Cross-Compiler (Best Approach) - Since my M1 Mac is ARM-based, install a cross-compiler targeting AArch64 Linux:

### 1. brew tap messense/macos-cross-toolchains

### 2. brew install aarch64-linux-gnu

### 3. brew install messense/macos-cross-toolchains/aarch64-unknown-linux-gnu

### Then compile C code using: aarch64-unknown-linux-gnu-gcc -static index.c -o executableFile

### Then, check if your binary is a Linux ELF file: file executableFile

### If you see ELF 64-bit LSB executable, ARM aarch64, then it's compiled as a pure Linux binary without macOS security measures. Meaning ✅ No macOS security measures ✅ Compiled exactly like on a Linux system ✅ Not dependent on macOS system libraries

### Next Steps

# 1️⃣ Run it on a Linux ARM machine (like a Raspberry Pi or a cloud VM). Since macOS cannot run ELF binaries natively, you need a real Linux environment.

# 2️⃣ Test with QEMU on Mac (if you want to run it locally): brew install qemu

# 3️⃣ Run the executable inside QEMU: qemu-aarch64 ./executableFile (This will emulate an ARM Linux system on your Mac without needing a VM!)
