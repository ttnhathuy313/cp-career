"""
A program that demonstrates a naive attempt at creating a collage.

Author: Raghuram Ramanujan
"""
from csc121.image import get_channel, write_jpg


def bad_collage():
    """
    Produces a shoddy collage by pasting pixel data from Ilsa over Rick. The
    output is written to a file named 'bad-collage.jpg'.
    """
    rick_red = get_channel('rick.jpg', 'red')
    rick_green = get_channel('rick.jpg', 'green')
    rick_blue = get_channel('rick.jpg', 'blue')

    ilsa_red = get_channel('ilsa.jpg', 'red')
    ilsa_green = get_channel('ilsa.jpg', 'green')
    ilsa_blue = get_channel('ilsa.jpg', 'blue')

    height = len(ilsa_red)
    width = len(ilsa_red[0])

    # We only modify the top left corner of Rick's image - this is the area
    # where we'll paste pixels from Ilsa over Rick. The rest of Rick remains
    # unchanged. This is why the loop below only ranges over the width and
    # height of Ilsa, rather than Rick.
    for row in range(height):
        for col in range(width):
            rick_red[row][col] = ilsa_red[row][col]
            rick_green[row][col] = ilsa_green[row][col]
            rick_blue[row][col] = ilsa_blue[row][col]

    write_jpg(rick_red, rick_green, rick_blue, 'bad-collage.jpg')

bad_collage()
