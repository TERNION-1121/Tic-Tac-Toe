import pygame

class Player():
    pass

class Board():
    GRID_COLOR = (200, 200, 200)
    SQUARE_COLOR = (10, 10, 10)
    grid = [[j for j in range(3)] for i in range(3)]

    height = 720; width = 720
    window = pygame.display.set_mode((height, width))
    pygame.display.set_caption("Tic Tac Toe")
    window.fill(GRID_COLOR)

    square_size = height // 3

    O = pygame.image.load(r"Images\o-mark.png").convert_alpha()
    X = pygame.image.load(r"Images\x-mark.png").convert_alpha()

    @staticmethod
    def check_quit():
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

    @staticmethod
    def get_mouse_click():
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

                if pygame.mouse.get_pressed()[0]:
                    pos = pygame.mouse.get_pos()
                    print(f"[{pos[1] // Board.square_size}], [{pos[0] // Board.square_size}]")
                    return(pos[1] // Board.square_size, pos[0] // Board.square_size)

    @staticmethod
    def display_mark(coords):
        Board.window.blit(Board.O, (coords[1] * Board.square_size, coords[0] * Board.square_size))
        pygame.display.update()

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

        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

                if pygame.mouse.get_pressed()[0]:
                    pos = pygame.mouse.get_pos()
                    coords = (pos[1] // Board.square_size, pos[0] // Board.square_size)
                    print(f"[{coords[0]}], [{coords[1]}]")
                    Board.window.blit(Board.O, (coords[1] * Board.square_size, coords[0] * Board.square_size))
                    pygame.display.update()

Board.main()