<h1 align = "center">❌ Tic-Tac-Toe ⭕</h1>
 <br>
 
This program is a Tic-Tac-Toe boardgame, which can be played in the terminal/console window; made in C.

![image](https://user-images.githubusercontent.com/97667653/222738507-3a5af10f-74b3-4c01-8a7d-6350fc0ba949.png)

Modes available to play:
1. Human v/s Human.
2. Human v/s A.I.	

<br>

## func `main()`

It comprises of various other functions, which control the various parts of the game.
Although the two main ones being:
- func `human_vs_human()`
- func `human_vs_ai()`
	
<hr>

### `human_vs_human()`

It allows two humans to play against each other, each time the turn alternating.

![image](https://user-images.githubusercontent.com/97667653/222739003-c72f0a79-827e-4563-bdd2-d7366fb9e339.png)
![image](https://user-images.githubusercontent.com/97667653/222739053-d4e367ff-b5b2-486d-852b-a36d204f8066.png)
![image](https://user-images.githubusercontent.com/97667653/222739175-e2bd231d-b3d2-4770-ae2a-d226820eff8c.png)

Upon *game over*, it stops the game.

![image](https://user-images.githubusercontent.com/97667653/222739420-c4b5abdf-1b0b-423f-86d1-9cbf7a9c0fdc.png)

<hr>

### `human_vs_ai()`

Initially, it offers a choice to the user.

![image](https://user-images.githubusercontent.com/97667653/222739716-0bbeca26-bc78-4cae-a267-6b7f0823cc3a.png)

Upon choice,
The game starts accordingly.

If the AI has to make the first move, it makes a random move using the func `random_pos()`.

Otherwise, it makes use of the [minimax](https://en.wikipedia.org/wiki/Minimax) algorithm to find the best possible move.
The A.I. move is determined upon the use of the functions `minimax()` and `find_best_move()`.

<br>

*P.S. You can't win against the A.I. :wink:, it's either a draw, or a win for the computer.. Enjoy!*

> You are free to contribute for this repository!
