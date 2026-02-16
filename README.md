# Pipex

A 42 school project that recreates the behavior of shell pipes (`|`) in C. This program allows you to chain two commands together, reading from an input file, processing through two commands, and writing to an output file.

## 📋 Description

`pipex` is a program that mimics the behavior of the shell command: 
```bash
< file1 cmd1 | cmd2 > file2
```

It takes exactly 4 arguments:
1. **Input file** - The file to read from
2. **Command 1** - The first command to execute
3. **Command 2** - The second command to execute  
4. **Output file** - The file to write the result to

The program uses Unix system calls (`fork`, `pipe`, `execve`, `dup2`) to create child processes, establish communication between them via pipes, and redirect input/output appropriately.

## ✨ Features

- Executes two commands in sequence with pipe communication
- Reads input from a file
- Writes output to a file
- Automatically finds command executables using the `PATH` environment variable
- Handles command parsing and argument separation
- Proper process management with fork and wait
- Error handling for invalid commands and file operations

## 🛠️ Requirements

- **OS**: Unix-like system (Linux, macOS)
- **Compiler**: `cc` (or `gcc`)
- **Make**: Build system

## 📦 Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd pipex
```

2. Build the project:
```bash
make
```

This will:
- Compile the `libft` library
- Compile all source files
- Create the `pipex` executable

## 🚀 Usage

```bash
./pipex file1 cmd1 cmd2 file2
```

### Example

```bash
# Create a test input file
echo "Hello World" > input.txt

# Run pipex with two commands
./pipex input.txt "grep Hello" "wc -w" output.txt

# Check the result
cat output.txt
```

This is equivalent to:
```bash
< input.txt grep Hello | wc -w > output.txt
```

### More Examples

```bash
# Count lines containing a pattern
./pipex file.txt "grep pattern" "wc -l" result.txt

# Sort and get unique lines
./pipex input.txt "sort" "uniq" output.txt

# Find files and count them
./pipex /dev/null "ls -la" "wc -l" count.txt
```

## 🔧 How It Works

1. **Argument Validation**: Checks that exactly 4 arguments are provided
2. **Path Resolution**: Extracts the `PATH` environment variable and splits it
3. **Command Parsing**: Splits commands and their arguments
4. **Executable Finding**: Searches for command executables in PATH directories
5. **Pipe Creation**: Creates a pipe for inter-process communication
6. **Child Process**: 
   - Opens the input file
   - Redirects stdin to the input file
   - Redirects stdout to the pipe's write end
   - Executes the first command
7. **Parent Process**:
   - Waits for the child to complete
   - Opens/creates the output file
   - Redirects stdin to the pipe's read end
   - Redirects stdout to the output file
   - Executes the second command

## 📁 Project Structure

```
pipex/
├── pipex.c          # Main program logic
├── pipex.h          # Header file with function declarations
├── pipex_utils.c    # Child and parent process functions
├── paths.c          # PATH handling and command resolution
├── Makefile         # Build configuration
└── libft/           # Custom C library
    ├── libft.h      # Library header
    ├── *.c          # Library source files
    └── Makefile     # Library build file
```

## 🔑 Key Functions

- `get_paths()` - Extracts PATH from environment variables
- `get_split_paths()` - Splits PATH into individual directories
- `get_commands()` - Parses command string into arguments
- `find_real_path()` - Finds the full path to an executable
- `child_process()` - Handles the first command execution
- `parent_process()` - Handles the second command execution
- `null_check()` - Validates input arguments

## 🧹 Cleanup

To remove compiled files:
```bash
make clean      # Remove object files
make fclean     # Remove executables and object files
make re         # Rebuild from scratch
```

## ⚠️ Limitations

- Only supports exactly 2 commands (not multiple pipes)
- Commands must be in the system PATH
- Basic error handling (may need enhancement)
- No support for here-documents or here-strings

## 📚 Technologies

- **C Programming Language**
- **Unix System Calls**: `fork()`, `pipe()`, `execve()`, `dup2()`, `waitpid()`
- **File I/O**: `open()`, `read()`, `write()`, `close()`
- **Custom Library**: `libft` (42's custom C library)


## 📝 License

This project is part of the 42 school curriculum.
