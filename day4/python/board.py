
class Board:
    def __init__(self,data):
        self.card = data
        self.marked = [[0]*5]*5

    def check_roll(self,roll):
        for i in range(5):
            for j in range(5):
                if self.card[i][j] == roll:
                    self.marked = 1

    def bingo(self):
        for i in range(5):
            h = self.marked[i][0] + self.marked[i][1] + self.marked[i][2] + self.marked[i][3] + self.marked[i][4]   
            v = self.marked[0][i] + self.marked[1][i] + self.marked[2][i] + self.marked[3][i] + self.marked[4][i]   

        if(h == 5 or v == 5):
            return True
        
        return False

    def get_unmarked_sum(self):
        total = 0
        for i in range(5):
            for j in range(5):
                if self.marked[i][j] == 0:
                    total = total + self.card[i][j]
