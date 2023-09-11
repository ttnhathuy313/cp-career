"""
Example of an image filter
Author: SD
"""

from csc121.image import get_channel, write_jpg

def remove_red():
    """
    Function that removes all red from a given image.
    """
    
    # Open the image file and store each channel in a
    # variable. Each of the variables is a nested list.
    red = get_channel('puffins.jpg', 'red')
    green = get_channel('puffins.jpg', 'green')
    blue = get_channel('puffins.jpg', 'blue')

    # Compute the height and the width of the image.
    # We could have used any of the channels for this,
    # as all the lists are the same size.
    height = len(red)
    width = len(red[0])
    
    # DO SOMETHING HERE.
    for row in range(height):
        for column in range(width):
            red[row][column] = 0
    
    # Write the modified file again.
    write_jpg(red, green, blue, 'nored.jpg')
    