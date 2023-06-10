# 42_push_swap

Completed with maximum moves efficiency 125/125
```
sorts stack size 3 in less than 3  moves
sorts stack size 5 in less than 10 moves
sorts stack size 100 in less than 700 moves
sorts stack size 500 in less than 5500 moves
```
## Usage
Push Swap program displays instructions that sorts the stack
```
./push_swap <int parameters to be sorted>
```
Checker program to check if moves sorts the stack correctly, displays OK if it sorts else KO
```
./checker <int parameters to be sorted>
[list of moves line after line on prompt && ctrl D to exit prompt and execute]
```

An algorithm that sorts a stack A using an empty stack B (Only allowed to use 11 moves to manipulate stacks)
These are the only allowed moves(No direct manipulation or changing of data directly allowed):

* ** sa (swap a)**: Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

* ** sb (swap b)**: Swap the first 2 elements at the top of stack b.Do nothing if there is only one or no elements.

* ** ss **: sa and sb at the same time.

* ** pa (push a)**: Take the first element at the top of b and put it at the top of a.Do nothing if b is empty.

* ** pb (push b)**: Take the first element at the top of a and put it at the top of b.Do nothing if a is empty.

* ** ra (rotate a)**: Shift up all elements of stack a by 1.The first element becomes the last one.

* ** rb (rotate b)**: Shift up all elements of stack b by 1.The first element becomes the last one.

* ** rr **: ra and rb at the same time.

* ** rra (reverse rotate a)**: Shift down all elements of stack a by 1.The last element becomes the first one.

* ** rrb (reverse rotate b)**: Shift down all elements of stack b by 1.The last element becomes the first one.
