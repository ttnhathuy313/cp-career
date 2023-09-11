
"""
A tutorial on using the image module.

Author: RR & SD
"""

#############################################################################
########## READ THE DIGITAL IMAGES HANDOUT AND SECTION 10.24 FROM  ##########
##########           THE TEXTBOOK BEFORE PROCEEDING!!             ###########
#############################################################################

# The image module is a custom module that was written for this class and is
# part of the csc121 package. It contains useful functions for reading and
# writing image data from JPG files (this is the most common format in which
# digital images are encoded).

# Loads the function we'll use from the image module.
from csc121.image import get_channel


def image_demo():
    """
    Demonstrates basic operations that are supported by the image module.
    """
    # There are a number of images for you to play around with. These are
    # contained in images.zip. Unzip these files and save them to the same
    # folder as this program. It's important to make sure that all these files
    # are living in the same folder --- the JPG files, and this image_demo.py
    # file. Otherwise, you will get an error message when you try to call the
    # image_demo() function.

    # Reading the data from a file: this is accomplished using the get_channel
    # function that requires two inputs - the name of the file to be opened and
    # the color channel whose data should be read (i.e., one of the strings
    # 'red', 'green, or 'blue'). This function outputs a nested list containing
    # the image data for the specified color channel. For example, the following
    # line reads in the red color data from the file 'puffins.jpg', and stores
    # the resulting nested list in a variable named red_data.
    red_data = get_channel('hw4/puffins.jpg', 'red')
    print(red_data[0][0])

    # Based on concepts covered in section 10.24, how can you determine the
    # dimensions of this image, i.e., its height and width as measured in
    # pixels? Write two lines of code below that would print out the height
    # and width of the image.

    # The top-left corner of the image has coordinates (0, 0), i.e.,
    # corresponds to the pixel at the 0th row and 0th column. Can you print
    # out the value of the red component of this pixel? How about the pixel
    # at the bottom-right corner?

image_demo()