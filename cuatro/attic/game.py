from easyAI import TwoPlayerGame
import random


class FourInLine(TwoPlayerGame):
    """ In turn, the players remove one, two or three bones from a
    pile of bones. The player who removes the last bone loses. """

    def __init__(self, N: int, players=None):
        self.players = players
        self.N = N
        self.grid = [[0] * N for _ in range(N)]
        self.current_player = 1  # player 1 starts
        self.remaining_moves = N * N
        self.haslost = None

        # yapf: disable
        self.pos_dirs = ([((i, 0), (0, 1)) for i in range(N)] +
                         [((0, j), (1, 0)) for j in range(N)] +
                         [((i, 0), (1, 1)) for i in range(N)] +
                         [((0, j), (1, 1)) for j in range(N)])
        # yapf: enable

    def possible_moves(self):
        moves = []
        for i in range(self.N):
            for j in range(self.N):
                if self.grid[i][j] == 0:
                    moves.append((i, j))
        random.shuffle(moves)
        return moves

    def make_move(self, move):
        (i, j) = move
        assert self.grid[i][j] == 0
        self.grid[i][j] = self.current_player
        self.remaining_moves -= 1

    def unmake_move(self, move):
        (i, j) = move
        self.grid[i][j] = 0
        self.remaining_moves += 1

    def is_over(self):
        return self.remaining_moves == 0 or self.lose()

    def lose(self):
        self.haslost = self.find_four(self.opponent_index)
        return self.haslost

    def scoring(self):
        if self.haslost != None:
            haslost = self.haslost
            self.haslost = None
            return -100 if haslost else 0
        else:
            return -100 if self.lose() else 0

    def show(self):
        for i in range(self.N):
            for j in range(self.N):
                c = self.grid[i][j]
                print(".OX"[c], end="")
            print()

    def find_four(self, player):
        for (i, j), (diri, dirj) in self.pos_dirs:
            streak = 0
            while (i < self.N) and (j < self.N):
                if self.grid[i][j] == player:
                    streak += 1
                    if streak == 4:
                        return True
                else:
                    streak = 0
                i += diri
                j += dirj
        return False

    def tie(self):
        return not self.lose()
