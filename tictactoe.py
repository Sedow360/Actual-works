import random as r

def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_winner(board):
    for row in board:
        if row[0] == row[1] == row[2] != " ":
            return row[0]
    
    for col in range(3):
        if board[0][col] == board[1][col] == board[2][col] != " ":
            return board[0][col]
    
    if board[0][0] == board[1][1] == board[2][2] != " ":
        return board[0][0]
    
    if board[0][2] == board[1][1] == board[2][0] != " ":
        return board[0][2]
    
    return None

def is_board_full(board):
    return all(cell != " " for row in board for cell in row)

def minimax(board, depth, is_maximizing):
    scores = {'X': -1, 'O': 1, 'draw': 0}
    winner = check_winner(board)
    
    if winner in scores:
        return scores[winner]
    
    if is_board_full(board):
        return scores['draw']
    
    if is_maximizing:
        best_score = -float('inf')
        for r in range(3):
            for c in range(3):
                if board[r][c] == " ":
                    board[r][c] = "O"
                    score = minimax(board, depth + 1, False)
                    board[r][c] = " "
                    best_score = max(score, best_score)
        return best_score
    else:
        best_score = float('inf')
        for r in range(3):
            for c in range(3):
                if board[r][c] == " ":
                    board[r][c] = "X"
                    score = minimax(board, depth + 1, True)
                    board[r][c] = " "
                    best_score = min(score, best_score)
        return best_score

def computer_move(board):
    best_score = -float('inf')
    best_move = (-1, -1)
    
    for r in range(3):
        for c in range(3):
            if board[r][c] == " ":
                board[r][c] = "O"
                score = minimax(board, 0, False)
                board[r][c] = " "
                if score > best_score:
                    best_score = score
                    best_move = (r, c)
    
    if best_move != (-1, -1):
        board[best_move[0]][best_move[1]] = "O"

def player_move(board):
    while True:
        try:
            move = input("Enter your move (row and column) as 'row col' (0, 1, or 2): ")
            row, col = map(int, move.split())
            if board[row][col] == " ":
                board[row][col] = "X"
                break
            else:
                print("Cell is already taken. Try again.")
        except (ValueError, IndexError):
            print("Invalid input. Please enter row and column as 'row col' (0, 1, or 2).")

def play_game():
    board = [[" " for _ in range(3)] for _ in range(3)]
    print("Welcome to Tic Tac Toe!")
    print_board(board)
    player_move(board)
    print_board(board)
    print("Computer's turn")
    while True:
        row, col = r.randint(0, 2), r.randint(0, 2)
        if board[row][col] == " ":
            board[row][col] = "O"
            break
    print_board(board)

    while True:
        # Player's turn
        player_move(board)
        print_board(board)
        if check_winner(board) == "X":
            print("Congratulations! You win!")
            break
        if is_board_full(board):
            print("It's a draw!")
            break

        print("Computer's turn")
        computer_move(board)
        print_board(board)
        if check_winner(board) == "O":
            print("Computer wins! Better luck next time.")
            break
        if is_board_full(board):
            print("It's a draw!")
            break

if __name__ == "__main__":
    play_game()