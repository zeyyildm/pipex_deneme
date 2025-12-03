# Pipex

A 42 School project that recreates the behavior of the shell pipe (`|`) operator, allowing two commands to communicate through a pipe mechanism.

## 🎯 About

**Pipex** is a program that mimics the behavior of the shell pipe operator. It takes an input file, two commands, and an output file, then executes the first command with the input file and pipes its output to the second command, which writes the result to the output file.

**Equivalent shell command:**
```bash
< infile cmd1 | cmd2 > outfile
```

**Pipex command:**
```bash
./pipex infile cmd1 cmd2 outfile
```

## ✨ Features

- ✅ Executes two commands in sequence with pipe communication
- ✅ Handles file input/output redirection
- ✅ Finds commands in PATH environment variable
- ✅ Proper error handling and memory management
- ✅ No memory leaks
- ✅ Supports command arguments

## 🚀 Installation

1. Clone the repository:
```bash
git clone <your-repo-url>
cd pipex_deneme
```

2. Build the project:
```bash
make
```

This will compile the `pipex` executable and the required `libft` library.

## 📖 Usage

```bash
./pipex <infile> <cmd1> <cmd2> <outfile>
```

### Arguments:
- `<infile>`: Input file to read from
- `<cmd1>`: First command with optional arguments (e.g., `"cat -e"`)
- `<cmd2>`: Second command with optional arguments (e.g., `"grep hello"`)
- `<outfile>`: Output file to write results to

### Example:
```bash
./pipex infile "cat -e" "grep hello" outfile
```

This is equivalent to:
```bash
< infile cat -e | grep hello > outfile
```

## 🔧 How It Works

1. **Initialization**: The program extracts the PATH from environment variables and parses the commands.

2. **Path Resolution**: It searches for the full path of each command in the PATH directories.

3. **Pipe Creation**: A pipe is created to enable communication between the two processes.

4. **Process Forking**: The program forks to create a child process.

5. **Child Process**: 
   - Opens the input file
   - Redirects stdin to the input file
   - Redirects stdout to the pipe's write end
   - Executes the first command

6. **Parent Process**:
   - Waits for the child process to complete
   - Opens the output file
   - Redirects stdin to the pipe's read end
   - Redirects stdout to the output file
   - Executes the second command

### Data Flow:
```
infile → cmd1 → pipe → cmd2 → outfile
```

## 📁 Project Structure

```
pipex/
├── pipex.c          # Main program and initialization
├── pipex_utils.c    # Child and parent process functions
├── paths.c          # PATH and command path resolution
├── pipex.h           # Header file with structures and prototypes
├── Makefile          # Build configuration
├── libft/            # Custom C library (42 School standard)
│   ├── libft.h
│   ├── libft.a
│   └── [libft source files]
└── README.md
```

### Key Functions:

- `init_pipex()`: Initializes the pipex structure with paths and commands
- `run_pipex()`: Creates pipe, forks process, and manages execution
- `child_process()`: Handles first command execution
- `parent_process()`: Handles second command execution
- `get_paths()`: Extracts PATH from environment variables
- `find_real_path()`: Finds the full path of a command
- `get_commands()`: Parses command string into arguments array

## 🛠 Technologies

- **C Programming Language**
- **Unix System Calls**: `pipe()`, `fork()`, `execve()`, `dup2()`, `waitpid()`
- **File Descriptors**: Input/output redirection
- **Process Management**: Fork and exec model

## 🧹 Cleanup

To remove compiled files:
```bash
make clean      # Remove object files
make fclean     # Remove executable and object files
make re         # Clean and rebuild
```

## 📝 Notes

- The program requires exactly 4 arguments (infile, cmd1, cmd2, outfile)
- Commands must be available in the system PATH
- The output file will be created if it doesn't exist, or truncated if it exists
- All file descriptors are properly closed to prevent memory leaks

## 📄 License

This project is part of the 42 School curriculum.

---
