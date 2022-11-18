from typing import Any
from easyAI import AI_Player, Negamax, SSS
import random
import sys
from game import FourInLine

random.seed(sys.argv[1])

N = int(sys.argv[2])
mode = sys.argv[3]

ai1: Any
ai2: Any

if mode == "win":
    while True:
        # give one ai advantage to increase chances for it to win
        players = [AI_Player(Negamax(3)), AI_Player(SSS(1))]
        random.shuffle(players)
        game = FourInLine(N=N, players=players)
        game.play(verbose=False)

        if not game.tie():
            break

if mode == "tie":
    assert N <= 5, "The chance of a tie on grids larger than 5 is too low"
    while True:
        # give both ais the same intelligence to increase chances for a tie
        players = [AI_Player(Negamax(3), AI_Player(Negamax(3)))]
        game = FourInLine(N=N, players=players)
        game.play(verbose=False)

        if game.tie():
            break

game.show()
