# pipex
This is one of the projects in the curriculum of 42 School.

## The goal of the school
The schools concept relies on you teaching yourself by learning how to do research and ask for help of your peers when needed. There are no teachers nor lectures. The curriculum includes planty of projects that you need to finish in order to progress and finish the school. The projects increase in difficulty as you go. Main programming language used in the school is `C` and on later stages of the curriculum `C++` besides these two you also learn about other stuff like: `Docker`, `Virtual Machines`, `networking` and more.

## The goal of the project
Aim of this project was to get familiar with how the redirections and pipes work in a linux system. I needed to create a program which can run to bash commands, the first one would have a input redirection from a file and the second one would redirect the output to a file. Bonus part of the project required me to implement same program with an random amount of cmds between the first and last command. It also supports here_doc instead of the first input redirection.

## In this project I learned:
  - How to use `pipe()`
  - How to use `fork()`
  - Working with `multiple processes`
  - What's the `PATH variable` in Linux and how to use it
  - How to use `execve()` to run binaries from a different program
  - What's `enviroment` in Linux
  - Properly `managing pipes` to not leak fd
  
## How to use it?
Clone the repository and run `make` in order to make the mandatory part. Program name is `pipex` and it takes 4 arguments. Run it as follows: `pipex *infile path* "cmd1 *options for the cmd1*" "cmd2 *options for the cmd2*" *outfile path*`. It is important to pass the commands and their options in one string otherwise they are considered as separate arguments. `Infile` is the input for `cmd1` and `outfile` is the output file for `cmd2` (_if file doesn't exist it will be created_, _the output file is oppened in truncate mode_). Commands can be passed by relative/absolute path or just by name. If path of the command is not passed program will search for it in `PATH` variable from the enviroment.

Example:
```
bash-3.2$ cat ../input_file
hello there

I like chocolate
Do you like chocolate ? :D
bash-3.2$ ./pipex ../input_file "cat -e" "cat -e" ../outfile
bash-3.2$ cat ../outfile
hello there$$
$$
I like chocolate$$
Do you like chocolate ? :D$$
```
In order to make bonus part run `make fclean` and then `make bonus`, program name is `pipex`. It's similar to mandatory part but you can pass n amount of commands, the only rule is n > 1. Instead of the first argument (the input file) you _can_ pass `here_doc *LIMITER*` limiter being the word that's used as the sign to stop reading. Using `here_doc` will also open the outputfile in _append_ mode.
Example:
```
bash-3.2$ cat ../input_file
hello there

I like chocolate
Do you like chocolate ? :D
bash-3.2$ ./pipex ../input_file "cat -e" "cat -e" "cat -e" "cat -e" ../outfile
bash-3.2$ cat ../outfile
hello there$$$$
$$$$
I like chocolate$$$$
Do you like chocolate ? :D$$$$
bash-3.2$ ./pipex here_doc END "cat -e" "cat -e" "cat -e" ../outfile
hello
there
END
bash-3.2$ cat ../outfile
hello there$$$$
$$$$
I like chocolate$$$$
Do you like chocolate ? :D$$$$
hello$$$
there$$$
```

_The `cat -e` command in the exmaples was used only for demonstration reasons, the progarmm can be used with any other commands from bash and it will behave in the proper way ❗_
