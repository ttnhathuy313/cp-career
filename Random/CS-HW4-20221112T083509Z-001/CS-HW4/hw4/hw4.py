from csc121.image import get_channel, write_jpg

def good_collage():

    rick_red = get_channel('rick.jpg', 'red')
    rick_green = get_channel('rick.jpg', 'green')
    rick_blue = get_channel('rick.jpg', 'blue')

    ilsa_red = get_channel('ilsa.jpg', 'red')
    ilsa_green = get_channel('ilsa.jpg', 'green')
    ilsa_blue = get_channel('ilsa.jpg', 'blue')
    
    height = len(ilsa_blue)
    width = len(ilsa_blue[0])
    
    for row in range(height):
        for col in range(width):
            gradient = max(1.0 * row / height, 1.0 * col / width)
            rick_blue[row][col] = int(ilsa_blue[row][col] * (1 - gradient)
            + rick_blue[row][col] * gradient)
            rick_red[row][col] = int(ilsa_red[row][col] * (1 - gradient) 
            + rick_red[row][col] * gradient)
            rick_green[row][col] = int(ilsa_green[row][col] * (1 - gradient) 
            + rick_green[row][col] * gradient)
    write_jpg(rick_red, rick_green, rick_blue, 'good-collage.jpg')
    
def mirror():
    image_name = input()
    image_red = get_channel(image_name, 'red')
    image_blue = get_channel(image_name, 'blue')
    image_green = get_channel(image_name, 'green')
    
    height = len(image_red)
    width = len(image_red[0])
    for j in range(width//2):
        for i in range(height):
            image_blue[i][width - j - 1] = image_blue[i][j]
            image_red[i][width - j - 1] = image_red[i][j]
            image_green[i][width - j - 1] = image_green[i][j]
    write_jpg(image_red, image_green, image_blue, 'mirrored.jpg')
    
