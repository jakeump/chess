# Chess

A command-line interface for the classic game of Chess.

## Motivation

I wanted to design and code this project because a) I love the game of Chess and b) it was a great way for me to practice my C++ skills. There are endless problems to solve, and I knew I was up for the challenge.

## The Process

I started by building the board, which is stored as a vector. To display the board, I needed to account for which indices of the vector corresponded to new lines. I also needed to build a checkerboard pattern and have the appropriate color in each square. When a piece moved from a square, the board updates the square's color to black or white, corresponding to its location. I also built a flipped board so the player using black pieces would have an appropriate perspective.

I then built each piece, utilizing a derived class structure. I built a Piece class, with functionality common to all pieces, such as color, name, and index. Then I constructed a derived class for each piece, which implemented move validation for each.

The driver file, Chess.cpp, brings it all together and, well, drives the game. It initializes all pieces, prints the board at each turn, verifies player input, captures pieces, and ensures invalid moves are not being made. There's always more to be added! For example, I have yet to implement the en passant maneuver or a checkmate detector.

![image](https://user-images.githubusercontent.com/87464153/167542976-a8f2c5e6-7f3e-4040-a1ed-714393423d99.png)
