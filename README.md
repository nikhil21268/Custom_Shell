
# Custom Linux Shell | Operating Systems Assignment

Built a fully functional Custom Linux Shell for Artix Linux, featuring essential commands like **cd**, **ls**, **echo**, **cat**, **date**, **mkdir**, **rm** and **pwd** 
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




### Options the shell commands can support:

1) **Cd** command - 
- **~**
- **/**
- **Blank**
- **Any other directory**

2) **pwd** command - 
- **-L**
- **–help**

3) **echo** command - 
- **\***
- **-n**

4) **ls** command - 
- **-a**
- **-l**

5) **cat** command - 
- **file1.txt file2.txt**
- **-n**
- **-b**

6) **date** command - 
- **-u**
- **-r**

7) **rm** command -
- **-v**
- **-i**

8) **mkdir** command -
- **-p**
- **-v**


