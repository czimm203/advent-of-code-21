from board import Board
with open("../test.txt","r") as f:
    lines = f.readlines()


rolls = [int(elem) for elem in lines[0].strip().split(',')]

data = []


for i,line in enumerate(lines[2:]):
    if(len(line) > 1):
        data.append([int(elem) for elem in line.strip().split()])

num_boards = len(data)//5

boards = []

for i in range(num_boards):
    card = [data[i*5],data[i*5 + 1],data[i*5 + 2],data[i*5 + 3],data[i*5 + 4]]
    boards.append(Board(card))

print(boards[1].marked[0][0])

for roll in rolls:
    for board in boards:
        board.check_roll(roll)
        if(board.bingo):
            print("BINGO!")
            print(roll * board.get_unmarked_sum())
            break
            break