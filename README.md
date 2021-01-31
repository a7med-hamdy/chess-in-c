# chess-in-c
chess game in c
 
Features:
Two players: Human vs Human.
Moves validation: the application checks if every move the player enters is valid before moving the piece. If the move is invalid a message “Invalid piece move” is displayed and asks the player of another move.
Check: when a player's king is attacked. If a check occurs a message “Check” is displayed.
Checkmate: game position in which a player's king is in check (threatened with capture) and there is no way to avoid the threat. If any player is checkmated a message” Checkmate” is displayed and the game ends.
Draw by:
Stalemate: game position in which a player has no legal moves to do.
Dead positions:
● King versus king
● king and bishop versus king
● king and knight versus king
● king and bishop versus king and bishop with the bishops on the same color.
If a draw occurs a message “Draw” is displayed and the game ends.
Castling: a special move in which the king is moved two squares toward the rook, and the rook moves past the king to the square right next to where the king has moved.
