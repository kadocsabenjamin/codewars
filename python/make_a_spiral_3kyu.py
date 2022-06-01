import sys

sys.setrecursionlimit(15000)


def spiralize(size):

    spiral = [[0 for x in range(0, size)] for y in range(0, size)]

    start_x = 0
    start_y = 0

    direction = 'right'

    spiral = place(spiral, start_x, start_y, direction, size)

    return spiral


def place(spiral, x, y, dir, size):

    if spiral[y][x] == 1:
        if dir == 'right':
            spiral[y][x - 1] = 0
        elif dir == 'down':
            spiral[y - 1][x] = 0
        elif dir == 'left':
            spiral[y][x + 1] = 0
        elif dir == 'up':
            spiral[y + 1][x] = 0

        return spiral

    spiral[y][x] = 1

    if dir == 'right':
        if x == size - 1:
            dir = 'down'
            y += 1
        elif x < size - 2:
            if spiral[y][x + 2] == 1:
                dir = 'down'
                y += 1
            else:
                x += 1
        else:
            x += 1

    elif dir == 'down':
        if y == size - 1:
            dir = 'left'
            x += -1
        elif y < size - 2:
            if spiral[y + 2][x] == 1:
                x += -1
                dir = 'left'
            else:
                y += 1
        else:
            y += 1

    elif dir == 'left':
        if x == 0:
            dir = 'up'
            y += -1
        elif x > 1:
            if spiral[y][x - 2] == 1:
                y += -1
                dir = 'up'
            else:
                x += -1
        else:
            x += -1

    elif dir == 'up':
        if y == 0:
            dir = 'right'
            x += 1
        elif y > 1:
            if spiral[y - 2][x] == 1:
                x += 1
                dir = 'right'
            else:
                y += -1
        else:
            y += -1

    place(spiral, x, y, dir, size)

    return spiral


s = spiralize(10)
for x in s:
    print(x)
