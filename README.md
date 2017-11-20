# Memory-Match-Game

### C++ code:
MemoryMatchGame.h   MemoryMatchGame.cpp
Grid.h              Grid.cpp
Theme.h             Theme.cpp


# Features:

## Menu User Interaction:

Level of Play – Use selects at start of game 4 x 4 grid (Easy) 6 x 6 grid (Moderate) 8 X 8 grid (Difficult)

Speed of Play – At start of game, User selects time interval for clicked-on term-pair to display 2 seconds (Difficult) 4 seconds (Moderate) 6 seconds (Easy)

User would select out of displayed themes  US States, ELEMENTS Symbols 

## Game:

Grid with randomly selected Terms from the theme array is populated at start of game based on user choices

During the course of play, the face/theme term in the display grid is replaced by a corresponding array terms, when user selects a grid square
  
  User selects a FIRST square, the theme/face term in the grid square is replace with correspond stored term, from the 2-dim answer array
  
  User selects a SECOND square, the term theme/face in the second grid square is replace with the corresponding stored term, from the 2-dim answer array
  
  The computer compares the terms for the two selected squares. If they are the same, the terms remain on the screen and can no longer be selected.
  If they are different, the term remain the screen for 2, 4 or 6 seconds, depending on user selection at the beginning of the game. After that elapse time, those two grid terms are replaced with the face/theme term.
  
  A timer keeps track of the number of seconds it took to solve a game.
  
  ## Interactive Output:
 <a href="https://imgflip.com/gif/1zq3py"><img src="https://i.imgflip.com/1zq3py.gif" title="made at imgflip.com"/></a>



