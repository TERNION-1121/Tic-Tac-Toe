import pygame

class Player():
    pass

class Board():
    GRID_COLOR = (200, 200, 200)
    SQUARE_COLOR = (10, 10, 10)
    grid = [dict.fromkeys(list(range(i-2, i+1)), None) for i in range(3, 10, 3)]

    height = 720; width = 720
    window = pygame.display.set_mode((height, width))
    window.fill(GRID_COLOR)

    @staticmethod
    def check_quit():
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

    @staticmethod
    def make_board():
        for row in Board.grid:
            for column in row:
                x = 0
                y = 0
                pygame.draw.rect(Board.window, Board.SQUARE_COLOR, pygame.Rect())

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