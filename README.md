
# Custom Linux Shell | Operating Systems Assignment

Built a fully functional Custom Linux Shell for Artix Linux, featuring essential commands like **cd**, **ls**, **echo**, **cat**, **date**, **mkdir**, **rm** and **pwd** 

# Problem Statement

## Basic Linux/Unix Shell Implementation

### Introduction

Linux and other Unix-like operating systems employ "shells," which are programs providing a command-line interface for users to input commands. This assignment focuses on creating a simple shell using standard C libraries and Linux system calls, such as fork(), exec() family system calls, and wait() family of system calls. The shell should handle both "internal" and "external" commands.

### Task Overview

1. **Internal Commands:**
   - Design a shell capable of handling three internal commands: `cd`, `echo`, and `pwd`.
   - Internal commands are interpreted by the shell itself without requiring external programs.
   - External commands include `ls`, `cat`, `date`, `rm`, and `mkdir`, which should be handled by separate programs.

2. **Shell Functionality:**
   - The shell should create new processes using fork() for external commands.
   - Use the exec() family system calls to run individual external command programs.
   - The parent process must wait for the child process to terminate using the wait() family of system calls.

### Tasks Breakdown

#### Task 1 - Shell Implementation with fork()/execl()
   - Design a shell capable of handling internal and external commands.
   - Implement external command programs (`ls`, `cat`, `date`, `rm`, and `mkdir`).
   - Document and demonstrate the correct functioning of each command with at least two options.
   - Handle corner cases such as invalid options with graceful degradation.

#### Task 2 - Shell Implementation with pthread_create()/system()
   - Achieve the same functionality as Task 1 but use pthread_create() instead of fork() for thread-based execution.
   - Use system() instead of execl() family functions to run external command programs.
   - Ensure the thread-based execution is triggered by commands followed by "&t".
   - The external command programs should be compatible with both fork()/execl() and pthread_create()/system() versions of the shell.


## Deployment

* To deploy this project, **cd** into the **ToRun** directory and run -
```bash
  make
```
* Now, run the **myShell** executable file using -
```bash
  ./myShell
```


## Documentation

Successfully handling atleast two corner cases for each of the commands and the assumptions I made -

1) **cd** command - 
Shell doesn’t execute if the number of arguments is more than 3.
It lets the user know if the file doesn’t exist.

2) **pwd** command - 
Only limited commands/options like -L etc. can be added after pwd command,  else the program gives an error message. Shell doesn’t execute if the number of arguments is more than 3.

3) **echo** command - 
If the command does not end with ‘&t’, and instead is followed by some strings after the ‘&t’, then instead of resulting in an error, the program doesn't stop its executing and treats the ‘&t’ character as normal user input, and prints it out on the console.
If the user doesn’t provide any input along with the echo command, then the shell, instead of throwing an error, simply prints out a newline character to the console.

4) **ls** command - 
Random strings entered after ls command, which are not valid options, do not stop the program’s execution & instead the program continues after displaying and error message.
No more than 3 args are allowed. If more args are passed, the program doesn’t execute the ls instruction, & instead prompts the user for a new instruction.

5) **cat** command - 
Graceful degradation if the file doesn't exist
-n and -b options only consider the first argument as the file & ignores the other arguments for printing out line numbers

6) **date** command - 
When checking for last modified timestamp of a datefile, if the file doesn't exist, the program doesn't terminate, but instead displays a default time and date of Thu Jan  1 05:30:00 1970.
Program generates an error message if random words are written after the -u option or after the file name in -v option.

7) **rm** command -
Handles deletion of multiple files at once without generating errors. Does not stop abruptly if the file does not exist.

8) **mkdir** command -
Supports multiple directory creation at once, without given errors.




### Supported Options for Shell Commands:

1. **Cd Command:**
   - `~` (Home directory)
   - `/` (Root directory)
   - Blank (Current directory)
   - Any other directory

2. **Pwd Command:**
   - `-L` (Follow symbolic links)
   - `--help` (Display help information)

3. **Echo Command:**
   - `*` (Wildcard character)
   - `-n` (Do not output the trailing newline character)

4. **Ls Command:**
   - `-a` (Show hidden files)
   - `-l` (Long format)

5. **Cat Command:**
   - `file1.txt file2.txt` (Concatenate files)
   - `-n` (Number all output lines)
   - `-b` (Number non-blank output lines)

6. **Date Command:**
   - `-u` (Display Coordinated Universal Time, UTC)
   - `-r` (Display the last modification time of a file)

7. **Rm Command:**
   - `-v` (Be verbose, show what is being done)
   - `-i` (Prompt before every removal)

8. **Mkdir Command:**
   - `-p` (Create parent directories if they do not exist)
   - `-v` (Be verbose, show what is being done)

