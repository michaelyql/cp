### Nim games
- **Nim**: Two players take turns removing 1 or more objects from any of a set of distinct pile of coins. Whoever has no coins left to remove loses (normal play).
- **Chomp**: given a n x m chocolate bar grid, the lower left corner is poisonous. Whoever eats it loses. Each player can chomp a square and it will remove all squares to the right and above the selected square. 
- **Subtract a square**: given a heap of n coins, each player takes a non-zero square number of coins. In normal play, whoever has no coins to remove loses.
- **Cram**: two players take turns putting 2x1 dominoes in either vertical or horizontal direction on a m x n grid. It can also be played on an irregular polygon or cylindrical board. Whoever has no moves left loses (normal play). A winning strategy would be to always copy the opponents move in the opposite orientation. 
- **Hackenbush**: [link](https://en.wikipedia.org/wiki/Hackenbush)

Normal play: last player who makes a move wins (player with no moves left loses)
Misere mode: last player who makes a move loses

### Variations of Nim
- **Subtraction game**: same as nim, but an upper limit is imposed on the max number of objects that a player can remove in one turn
- **21 game**: (Misere) The first player says 1, each subsequent player must increase from the previous number by at least 1 and at most 3. Whoever says "21" loses. Other variations include "Add at most 5; lose on 34"
- **100 game**: Two players start from 0, each taking turn to add a value from 1 to 10 to the sum. Whoever reaches 100 on their turn wins.
- **Multiple-heap rule nim**: like nim, but each turn a player can remove the same number of objects from *each* heap.
- **Circular nim**: any number of objects are placed on a line, in each turn a player can remove 1, 2 or 3 adjacent objects (with loop around from the end to start). Whoever cannot remove any object loses
- **Grundy's game**: like nim, but in each turn, a player separates one heap into two new heaps of strictly different sizes. Whoever has no moves loses.
- **Greedy nim**: like nim, but in each turn a player is restricted to choosing only from the heap with the most number of objects. 
- **Candy nim**: like nim, each person tries to take the last candy, but each person also tries to take the maximum amount of candies 
- **Fibonacci nim**: like nim, but in each turn a player can only take at most twice as many objects as the previous move. 

[Introduction to Game Theory](https://youtube.com/playlist?list=PLOzRYVm0a65fY-Vh8Caiv3wAYmDd7SnrN&si=0zKovUXVh9HFh7Eo)

### Impartial Games
In combinatorial game theory, an *impartial* game is a game in which the allowable moves is only dependent on the current position of the game, and not which player is moving. 

Impartial games are played with perfect information and no chance moves, i.e. all information about the game are known to both players. 

Sprague-Grundy theorem states that every impartial game under normal play is equivalent to a **nimber**.

Impartial game requirements:
- Two players take turns until a final state is reached (**terminal** position)
- A winner is chosen when one player has no moves to make
- There is a *finite* number of positions and operations for both players (no cycles in the game states)
- All operations must be available for both sides
- No action can be reliant on chance

### Sprague-Grundy Function
If x is a terminal position (no more moves left for the current player), g(x) = 0

g(x) = mex{g(y): y ∈ F(x)}

### Games
A game consists of a graph G=(X, F), where X is the set of all possible positions, and F is a function that, for all x ∈ X, gives a subset of the possible positions to move to, called followers. If F(x) is empty, then x is a terminal position. 

The starting position is x0 ∈ X. Player 1 moves from x0. 

Multiple games at one time: E.g. two players can remove either 1, 2 or 3 coins from a pile, and there are multiple piles of coins. Whoever is unable to remove a coin from any pile loses. This would be represented using two games G1(X1, F1) and G2(X2, F2). 

F(x1, x2) -> (y1, x2) for y1 ∈ F(x1) and F(x1, x2) -> (x1, y2) for y2 ∈ F(x2).

Then F(x1, x2) = F1(x1) × {x2} U {x1} × F2(x2)

G = G1 + G2 + ... + Gn (for n simultaneous games)

X = x1 × x2 × x3 × ... × xn

F = F1(x1) × {x2} × {x3} × ... × {xn} U F2(x2) × {x1} × {x3} × ... × {xn} U ... U Fn(xn) × {x1} × {x2} × ... × {x_(n-1)}

Terminal position is the cartesian product of terminal positions in the individual games. 

### P and N positions
- Definition: a position is a terminal position iff there are no moves for the current player. 
- Definition: if a position is terminal, then it's a P-position. If there is **any** move from a given position to a P-position, then that position is a N-position. If all moves from a position are leading to N-positions, then that position is a P-position.

### Nim Addition
