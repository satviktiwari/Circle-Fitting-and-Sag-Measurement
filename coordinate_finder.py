import cv2
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

# img1 = cv2.imread("0.jpg")
# img2 = cv2.imread("30.jpg")
# img3 = cv2.imread("60.jpg")
# img4 = cv2.imread("90.jpg")
# img5 = cv2.imread("120.jpg")
# img6 = cv2.imread("150.jpg")
# img7 = cv2.imread("180.jpg")
# img8 = cv2.imread("210.jpg")
# img9 = cv2.imread("240.jpg")
# img10 = cv2.imread("270.jpg")
# img11 = cv2.imread("300.jpg")
# img12 = cv2.imread("330.jpg")
# img13 = cv2.imread("360.jpg")

# img1 = cv2.resize(img1, (1920,1080))
# img2 = cv2.resize(img2, (1920,1080))
# img3 = cv2.resize(img3, (1920,1080))
# img4 = cv2.resize(img4, (1920,1080))
# img5 = cv2.resize(img5, (1920,1080))
# img6 = cv2.resize(img6, (1920,1080))
# img7 = cv2.resize(img7, (1920,1080))
# img8 = cv2.resize(img8, (1920,1080))
# img9 = cv2.resize(img9, (1920,1080))
# img10 = cv2.resize(img10, (1920,1080))
# img11 = cv2.resize(img11, (1920,1080))
# img12 = cv2.resize(img12, (1920,1080))
# img13 = cv2.resize(img13, (1920,1080))

# final_img1 = cv2.add(img1, img2)
# final_img2 = cv2.add(img3, img4)
# final_img3 = cv2.add(img5, img6)
# final_img4 = cv2.add(img7, img8)
# final_img5 = cv2.add(img9, img10)
# final_img6 = cv2.add(img11, img12)

# final_img7 = cv2.add(final_img1, final_img2)
# final_img8 = cv2.add(final_img3, final_img4)
# final_img9 = cv2.add(final_img5, final_img6)

# final_img10 = cv2.add(final_img7, final_img8)
# final_img11 = cv2.add(final_img9, img13)

# final_img12 = cv2.add(final_img10, final_img11)
# final_img12 = cv2.resize(final_img12, (1920,1020))

# # plt.imshow(final_img12)

# cv2.imwrite("final_img12.jpg", final_img12)
img = mpimg.imread('Test HB Image.jpg')
# color_select = np.copy(image)
# plt.imshow(color_select)
# plt.show()

def click_event(event, x, y, flags, params):

	# checking for left mouse clicks
	if event == cv2.EVENT_LBUTTONDOWN:

		# displaying the coordinates
		# on the Shell
		print(x, ' ', y)

		# displaying the coordinates
		# on the image window
		font = cv2.FONT_HERSHEY_SIMPLEX
		cv2.putText(img, str(x) + ',' +
					str(y), (x,y), font,
					1, (255, 0, 0), 2)
		cv2.imshow('image', img)

	# checking for right mouse clicks	
	if event==cv2.EVENT_RBUTTONDOWN:

		# displaying the coordinates
		# on the Shell
		print(x, ' ', y)

		# displaying the coordinates
		# on the image window
		font = cv2.FONT_HERSHEY_SIMPLEX
		b = img[y, x, 0]
		g = img[y, x, 1]
		r = img[y, x, 2]
		cv2.putText(img, str(b) + ',' +
					str(g) + ',' + str(r),
					(x,y), font, 1,
					(255, 255, 0), 2)
		cv2.imshow('image', img)

# driver function
if __name__=="__main__":

	# reading the image
	# img = cv2.imread('final_img12.jpg')

	# displaying the image
	cv2.imshow('image', img)

	# setting mouse hadler for the image
	# and calling the click_event() function
	cv2.setMouseCallback('image', click_event)

	# wait for a key to be pressed to exit
	cv2.waitKey(0)

	# close the window
	cv2.destroyAllWindows()
