#! /usr/bin/local/python3

def print_welcome_message():
    print("Welcome to tic-tac-toe profession v0.1")
    print()


def get_placeholder_values():
    return 1, -1, 0


def build_empty_board(emptyValue):
    e = emptyValue
    game = [
        [e, e, e],
        [e, e, e],
        [e, e, e],
    ]
    return game


def print_board(game, x, o):
    for row in game:
        for c in row:
            print('x' if c == x else ('o' if c == o else '.'), end=' ')
        print()
    print()


def find_winner(game):
    winner = None
    for i in range(3):
        sums = [
            game[0][0] + game[0][1] + game[0][2],  # row 1
            game[1][0] + game[1][1] + game[1][2],  # row 2
            game[2][0] + game[2][1] + game[2][2],  # row 3
            game[0][0] + game[1][0] + game[2][0],  # col 1
            game[0][1] + game[1][1] + game[2][1],  # col 2
            game[0][2] + game[1][2] + game[2][2],  # col 3
            game[0][0] + game[1][1] + game[2][2],  # diagonal 1
            game[0][2] + game[1][1] + game[2][0]  # diaglonal 2
        ]

        if 3 in sums:
            winner = "X"

        if -3 in sums:
            winner = "O"

    return winner


def print_current_player(turn):
    if turn == 1:
        print("It's X's turn.")
    else:
        print("It's O's turn.")


def get_value_for_current_player(turn, x, o):
    if turn == 1:
        return x
    else:
        return o


def query_placement_from_user():
    row = int(input("Choose row (zero based): "))
    col = int(input("Choose column (zero based): "))
    return row, col


def cell_already_played(row, col, game, empty):
    return not game[row][col] == empty


def play_cell(game, row, col, active_value):
    game[row][col] = active_value


def main():
    # Print out cheesy welcome
    print_welcome_message()

    x, o, e = get_placeholder_values()
    game = build_empty_board(e)

    print("The board is set:")
    print_board(game, x, o)

    turn = 1
    active_value = None
    winner = None

    while not find_winner(game):
        # print who's turn it is (X or O)
        print_current_player(turn)

        # get the value of the player who's turn it currently is.
        active_value = get_value_for_current_player(turn, x, o)
        row, col = query_placement_from_user()

        # verify that entry is not already chosen
        if cell_already_played(row, col, game, e):
            print("Sorry, that position is already occupied with a {0}!".format(game[row][col]))
            print("try again")
            print_board(game, x, o)
            print()
            continue

        # play the cell
        play_cell(game, row, col, active_value)

        print("Excellent choice:")
        print_board(game, x, o)

        print()

        # check for a winner
        print("We're checking for a winner...")
        winner = find_winner(game)
        if not winner:
            print("No winner yet, keep going!")
            print()

        turn *= -1

    # Announce winner and show the winning board.
    print("We have a winner! It's the " + winner + "'s!")
    print("Way to win the day")
    print()
    print_board(game, x, o)


if __name__ == "__main__":
    main()