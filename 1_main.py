import pygame

class Player():
    pass

class Board():
    GRID_COLOR = (200, 200, 200)
    SQUARE_COLOR = (10, 10, 10)
    grid = [[j for j in range(3)] for i in range(3)]

    height = 720; width = 720
    window = pygame.display.set_mode((height, width))
    window.fill(GRID_COLOR)

    square_size = height // 3

    @staticmethod
    def check_quit():
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

    @staticmethod
    def make_board():
        for row in range(len(Board.grid)):
            for column in range(len(Board.grid[row])):
                x = Board.square_size * column
                y = Board.square_size * row
                pygame.draw.rect(Board.window, Board.SQUARE_COLOR, pygame.Rect(x, y, Board.square_size - 1, Board.square_size - 1))
        pygame.display.flip()

    @staticmethod
    def main():
        pygame.init()
        
        height = 720; width = 720
        window = pygame.display.set_mode((height, width))
        window.fill(Board.GRID_COLOR)
        pygame.display.flip()

        Board.make_board()
        Board.check_quit()

Board.main()