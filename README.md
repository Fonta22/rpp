# r++
A command line tool to run **C++** code without having to create an executable each time.

It is very useful during development since it compiles the code and runs it for you in one single command, storing the `.exe` file in the `%tmp%` directory and after deleting it.

## Usage
```cmd
r++ script.cpp arg[0]..arg[n]
```

## Example
```cmd
> r++ hello_world.cpp
Hello, World!
```

## Comparison
Running it the regular way would be:
```cmd
> g++ -o hello_world.exe hello_world.cpp
> hello_world
Hello, World!
```

Which is fine, but when you have to repeat it so much times while developing a program turns out to be annoying.

> *Farregós* situation...