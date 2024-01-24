# Pipex

This project will let us get familiar and find the details of UNIX pipe mechanism. The program is made with C language and the purpose is to simulate UNIX pipe according to below descriptions. 

## Description of the Mandatory part

The program replicates the behavior of the shell command: 

```
$> < file1 cmd1 | cmd2 > file2.
```

By executing the program:

```
$> ./pipex file1 cmd1 cmd2 file2
```

The program also Handles errors, such as wrong commands, permission issues with files, and more.

## Description of the bonus part

The first bonus part expands the program to handle multiple commands:

```
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

By executing the program:

```
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

The second bonus part will let us use the UNIX operations « and »:

```
cmd << LIMITER | cmd1 >> file
```

By executing the program and defining the first argument as ¨here_doc¨:

```
$> ./pipex here_doc LIMITER cmd cmd1 file
```

