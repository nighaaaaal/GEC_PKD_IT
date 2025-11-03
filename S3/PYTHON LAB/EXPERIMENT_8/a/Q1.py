import cv2
from matplotlib import pyplot as plt

# Attempt to read the image from the specified file path
# The 'r' before the string makes it a raw string, which prevents backslashes from being treated as escape characters
image = cv2.imread(r"S3/PYTHON LAB/EXPERIMENT_8/a/cat.jpg")

# Check if the image was loaded successfully
# cv2.imread returns None if the file doesn't exist or is corrupted
if image is None:
    print("Error: Image not found or cannot be read.")
else:
    print("Image loaded succesfully")

    # --- OpenCV Operations ---

    # Save the loaded image (which is in BGR format) to a new file
    cv2.imwrite("S3/PYTHON LAB/EXPERIMENT_8/a/saved_image.jpg", image)
    print("Image is succesfully saved as 'saved_image.jpg'")

    # Display the image in a window managed by OpenCV
    # The first argument is the window title
    cv2.imshow("OpenCV Image Window", image)

    # Wait indefinitely for a key press (0 means wait forever)
    # This keeps the window open until the user interacts with it
    cv2.waitKey(0)

    # Close all OpenCV windows that were created
    cv2.destroyAllWindows()

    # --- Matplotlib Operations ---

    # Convert the image from BGR (OpenCV's default color order) to RGB
    # Matplotlib expects images to be in RGB order, so this step is
    # crucial to display the colors correctly.
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    # Display the RGB image using Matplotlib
    plt.imshow(image_rgb)

    # Set a title for the Matplotlib plot
    plt.title("Displayed Image using Matplotlib")

    # Hide the x and y axes for a cleaner look
    plt.axis('off')

    # Show the Matplotlib plot window
    plt.show()