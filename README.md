# 42-get_next_line
The aim of this project is to make you code a function 
that returns a lineending with a newline, 
read from a file descriptor.


## Flowchart

1. set the static variable and read the file
2. move the strings buffer in the static
3. Analys static

a. static has 1 or many break line
1. set a new string with a line
2. remove the 1st line in static

b. static hasn't any break line
1. set a new string
2. re-read the file
3. analys again the buffer


```
    ┌────────────────┐
Buff│hey\nHow are y\0│
    └────────────────┘

    ┌─┐
Line│0│
    └─┘

    ┌─┐
Rest│0│
    └─┘

    ┌────────────────┐
Buff│hey\nHow are y\0│
    └────────────────┘

    ┌───────┐
Line│hey\n\0│
    └───────┘

         ┌───────────┐
Rest 0   │How are y\n│
         └───────────┘
```
