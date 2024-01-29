# Pipex

This project will let us get familiar with UNIX pipe mechanism and teach UNIX commands. The purpose of the program is to simulate UNIX pipe according to below steps. 

## Description of the Mandatory part

Replicate the behavior of the shell command: 

```
$> < file1 cmd1 | cmd2 > file2.
```

By executing:

```
$> ./pipex file1 cmd1 cmd2 file2
```

Error handling includes nonexistent commands, permission issues with files, and failures of used library functions.

## Description of the bonus part

The first bonus part expands the program to handle multiple commands:

```
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

By executing:

```
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

The second bonus part will let us use the UNIX operations « and » with limiter:

```
cmd << LIMITER | cmd1 >> file
```

By executing the program and defining the first argument as ¨here_doc¨:

```
$> ./pipex here_doc LIMITER cmd cmd1 file
```

