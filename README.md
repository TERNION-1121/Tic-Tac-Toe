<h1 align = "center">Tic-Tac-Toe</h1>
 <br>
 
This program is a two-player, Tic-Tac-Toe boardgame, which can be played in the terminal/console window.
- `xState = [0,0,0,0,0,0,0,0,0]` :  This list stores the positions where `X` has been marked.
- `oState = [0,0,0,0,0,0,0,0,0]` :  This list stores the positions where `O` has been marked.

## Functioning

The program works upon three functions defined, namely:
- `board()`
- `checkwin()`
- `game()`
<br>

### Working of `board()`

The `board()` function prints the gameboard for the game. 
It makes use of this simple logic to mark the `X`/`O` on the board:-
`num = 'X' if xState[numc] else ('O' if oState[numc] else numc)`
Here, `num` is the position's name in words **(zero, one.... eight)**, whereas `numc` is the cardinal value of `num`, **(0-8)**.
```py
    zero = 'X' if xState[0] else ('O' if oState[0] else 0)
    one = 'X' if xState[1] else ('O' if oState[1] else 1)
    two = 'X' if xState[2] else ('O' if oState[2] else 2)
    three = 'X' if xState[3] else ('O' if oState[3] else 3)
    four = 'X' if xState[4] else ('O' if oState[4] else 4)
    five = 'X' if xState[5] else ('O' if oState[5] else 5)
    six = 'X' if xState[6] else ('O' if oState[6] else 6)
    seven = 'X' if xState[7] else ('O' if oState[7] else 7)
    eight = 'X' if xState[8] else ('O' if oState[8] else 8)
```

Further it prints the gameboard:
```py
	print(f" | {zero} | {one} | {two} | ")
	print(f"-|---|---|---|-")
	print(f" | {three} | {four} | {five} | ")
	print(f"-|---|---|---|-")
	print(f" | {six} | {seven} | {eight} |")
```
<br>

### Working of `checkwin()`

The `checkwin()` function checks whether any player had won or not. It does so by checking all possible winning positions-combinations.
```py
wins = [[0,1,2], [3,4,5], [6,7,8], [0,3,6], [1,4,7], [2,5,8], [0,4,8], [2,4,6]]
for win in wins:
    if xState[win[0]] + xState[win[1]] + xState[win[2]] == 3:
        print("'X' Won the game!")
        return 1
    elif oState[win[0]] + oState[win[1]] + oState[win[2]] == 3:
        print("'O' Won the game!")
        return 0
return -1
```
<br>

It returns `1` if player `X` is found to be won, elsewise it returns `0` if player `O` is found to be won.
In cases where it no one have won, it returns `-1`, indicating a **Draw**.
<br>

### Working of `game()`
The `game()` function has four variables defined at its beginning:
```py
iterations = 0
xState = [0,0,0,0,0,0,0,0,0]
oState = [0,0,0,0,0,0,0,0,0]
turn = 1
```
`iterations` indicate the number of times the function had iterated; and a winner is declared under 8 iterations, else, when it's equal to 9, the game is considered a **Draw**.

`turn` indicates whose turn it is while marking there position with there corresponding mark(`X`/`O`).

An infinite-while loop iterates,
Upon printing the gameboard, the if-else condition check whose turn it is.

While taking the value input from the user, it is checked whether that corresponding position is already occupied or not, if yes, it asks the user to reconsider their choice, otherwise it continues the execution.

```py
while True:
            board(xState, oState)
            if turn == 1:
                print('X\'s turn')
                value = int(input("Enter the box no. where you want to place your 'X': "))
                while True:
                    if oState[value] == 0 and xState[value] == 0:
                        xState[value] = 1
                        break
                    else:
                        print("That box is already occupied!")
                        value = int(input("Enter the box no. where you want to place your 'X': "))
                turn = 0
				
            else: 
                print('O\'s turn')
                value = int(input("Enter the box no. where you want to place your 'O': "))
                while True:
                    if oState[value] == 0 and xState[value] == 0:
                        oState[value] = 1
                        break
                    else:
                        print("That box is already occupied!")
                        value = int(input("Enter the box no. where you want to place your 'O': "))

                turn = 1
				
```
<br>

![image](https://user-images.githubusercontent.com/97667653/178468909-bdde81ae-0b01-4f8f-b3be-aa7838ed8ebe.png)
> An example where the user tries to mark their `O` on a position which is already occupied.
<br>

After this block of code gets executed in each iteration, `iterations` is incremented by `1`.

Further this logic is implemented to terminate the game upon the result returned by `checkwin()`:-
```py
 cwin = checkwin(xState,oState)
 if cwin != -1: 
     print("Match Over")
     break
 elif iterations == 9:
     print("Draw!")
     board(xState, oState)
     break
else: None
```
<br>

The game is declared a **Draw**, if all the positions are occupied, but no winner is produced 
*(i.e. in case of iterations being equal to 9, and the result yielded by checkwin() is -1)*.

<img src = "https://user-images.githubusercontent.com/97667653/178469290-d3240b58-6b93-4bfd-99fe-d4de676d5cbc.png" align = "center">
<img src = "https://user-images.githubusercontent.com/97667653/178469400-f8dbac06-0b7b-4271-9e56-7de147ad73d6.png" align = "middle">

> A sample game
