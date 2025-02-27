🔹 How GCC Compiles C Code

When you run gcc myfile.c -o myfile, the compilation happens in four main steps:

1️⃣ Preprocessing (cpp) → Handles #include, #define, and macros.

# gcc -E myfile.c -o myfile.i (Produces a temporary .i file.)

2️⃣ Compilation (cc1) → Converts C code into assembly.

# gcc -S myfile.i -o myfile.s (Translates C code into assembly language (.s file))

3️⃣ Assembly (as) → Converts assembly into machine code (object file).

# gcc -c myfile.s -o myfile.o (Converts assembly into machine code (binary .o file))

4️⃣ Linking (ld) → Combines object files into an executable.

# gcc myfile.o -o myfile (Links myfile.o with libraries (libc, printf, etc.)) - Produces the final executable (myfile)

💡 Without linking, the program won’t run because functions like printf() need external libraries!

🔹 Does GCC Compile Directly to Machine Code?
🔴 NO – it first generates assembly code before converting it into machine code.
🟢 BUT – it does automate all steps, so to the user, it feels like a direct compilation
