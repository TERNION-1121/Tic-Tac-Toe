import pygame

class Board():
    GRID_COLOR = (200, 200, 200)
    SQUARE_COLOR = (10, 10, 10)
    grid = [[0 for j in range(3)] for i in range(3)]

    height = 720; width = 720
    window = pygame.display.set_mode((height, width))
    pygame.display.set_caption("Tic Tac Toe")
    window.fill(GRID_COLOR)

    square_size = height // 3

    turn = 1

    @staticmethod
    def check_quit(event):
        if event.type == pygame.QUIT:
            return False
        return True

    @staticmethod
    def make_board():
        pygame.init()
        height = 720; width = 720
        window = pygame.display.set_mode((height, width))
        window.fill(Board.GRID_COLOR)
        pygame.display.flip()

        for row in range(len(Board.grid)):
            for column in range(len(Board.grid[row])):
                x = Board.square_size * column
                y = Board.square_size * row
                pygame.draw.rect(Board.window, Board.SQUARE_COLOR, pygame.Rect(x, y, Board.square_size - 1, Board.square_size - 1))
        pygame.display.flip()

class Player(Board):
    O = pygame.transform.scale(pygame.image.load(r'Images\o-mark.png').convert_alpha(), (230, 230))
    X = pygame.transform.scale(pygame.image.load(r'Images\x-mark.png').convert_alpha(), (230, 230))

    turn = 1
    chances = 0
    
    @staticmethod
    def place_mark():
        if pygame.mouse.get_pressed()[0]:
            pos = pygame.mouse.get_pos()
            x = pos[1] // Board.square_size
            y = pos[0] // Board.square_size
            if not(Board.grid[x][y]):
                if Board.turn:
                    Board.window.blit(Player.O, (y * Board.square_size, x * Board.square_size))
                else:
                    Board.window.blit(Player.X, (y * Board.square_size, x * Board.square_size))
                pygame.display.flip()
                Board.grid[x][y] = 'O' if Board.turn else 'X'
                Board.turn = not(Board.turn)
                Player.chances+=1

    @staticmethod
    def isGameOver():
        for row in range(len(Board.grid)):
            if Board.grid[row] == ['X', 'X', 'X']:
                print("X won")
                return 0
            elif Board.grid[row] == ['O', 'O', 'O']:
                print("O won")
                return 1
            
            elif Board.grid[0][row] == Board.grid[1][row] == Board.grid[2][row]:
                if Board.grid[0][row] == "X":
                    print("X won!")
                    return 0
                elif Board.grid[0][row] == "O":
                    print("O won!")
                    return 1
        else:
            if Board.grid[0][0] == Board.grid[1][1] == Board.grid[2][2]:
                if Board.grid[0][0] == 'X':
                    print("X won")
                    return 0
                elif Board.grid[0][0] == 'O':
                    print("O won!")
                    return 1
                
            if Board.grid[0][2] == Board.grid[1][1] == Board.grid[2][0]:
                if Board.grid[0][2] == 'X':
                    print("X won!")
                    return 0
                elif Board.grid[0][2] == 'O':
                    print("O won!")
                    return 1
                
            if Player.chances == 9:
                print("Draw!")
                return -1
                
    @staticmethod
    def main():
        Board.make_board()

        running = True
        while running:
            for event in pygame.event.get():
                running = Board.check_quit(event)
                Player.place_mark()
                val = Player.isGameOver()
                if val in (0, 1, -1):
                    running = False

        running = True
        while running:
            for event in pygame.event.get():
                running = Board.check_quit(event)
        
        pygame.quit()
                    
Player.main()