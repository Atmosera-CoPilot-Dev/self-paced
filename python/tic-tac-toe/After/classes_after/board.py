class Board:
    def __init__(self):
        self.x = 1
        self.o = -1
        self.empty = 0
        self.cells = self.build_empty_board()

    def build_empty_board(self):
        cells = [
            [self.empty, self.empty, self.empty],
            [self.empty, self.empty, self.empty],
            [self.empty, self.empty, self.empty],
        ]
        return cells

    def print_board(self):
        for row in self.cells:
            for c in row:
                print('x' if c == self.x else ('o' if c == self.o else '.'), end=' ')
            print()

    def __str__(self):
        text = ""
        for row in self.cells:
            for c in row:
                text += 'x' if c == self.x else ('o' if c == self.o else '.')
            text += "\n"
        return text
