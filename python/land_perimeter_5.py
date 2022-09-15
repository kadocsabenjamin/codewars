land = "X"
water = "O"


def land_perimeter(arr):
    perimeters = 0
    for y in range(len(arr)):
        for x in range(len(arr[y])):
            if arr[y][x] == land:
                if y-1 >= 0:
                    if arr[y-1][x] == water:
                        perimeters += 1
                else:
                    perimeters += 1
                if y+1 <= len(arr)-1:
                    if arr[y+1][x] == water:
                        perimeters += 1
                else:
                    perimeters += 1
                if x-1 >= 0:
                    if arr[y][x-1] == water:
                        perimeters += 1
                else:
                    perimeters += 1
                if x+1 <= len(arr[y])-1:
                    if arr[y][x+1] == water:
                        perimeters += 1
                else:
                    perimeters += 1

    return 'Total land perimeter: {}'.format(perimeters)


print(land_perimeter(["XXXXXOOO", "OOXOOOOO",
      "OOOOOOXO", "XXXOOOXO", "OXOXXOOX"]))
