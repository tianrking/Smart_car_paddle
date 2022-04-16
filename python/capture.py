import sys
import time
import cv2
import numpy as np

def main(src,shape=[640, 480]):
	t = 0
	t1,t2,t3,t4 = 0,0,0,0
	new_src = "/dev/video" + str(src)
	camera = cv2.VideoCapture(new_src)
	camera.set(cv2.CAP_PROP_FRAME_HEIGHT, shape[0])
	camera.set(cv2.CAP_PROP_FRAME_WIDTH, shape[1])
	while 1==1:
		# While Balance
		# start_time = time.time()
		# while time.time() - start_time < 3:
		# camera.read()
	# for i in range(10):
		return_value, image = camera.read()
		cv2.imshow("image",image)
		k=cv2.waitKey(1)
		if k==27:
			break
		# if k==ord('1'): # ban
		# 	cv2.imwrite('./ban/{}.jpg'.format(t1), image)
		# 	print("ban ",t1)
		# 	t1 = t1 + 1
		# if k==ord('2'): # working
		# 	cv2.imwrite('./working/{}.jpg'.format(t2), image)
		# 	print("working ",t2)
		# 	t2 = t2 + 1
		# if k==ord('3'): # fork
		# 	cv2.imwrite('./fork/{}.jpg'.format(t3), image)
		# 	print("fork ",t3)
		# 	t3 = t3 + 1
		# if k==ord('4'): # bridge
		# 	cv2.imwrite('./bridge/{}.jpg'.format(t4), image)
		# 	print("bridge ",t4)
		# 	t4 = t4 + 1
		
		if k==ord('a'): # ban
			cv2.imwrite('./images/{}.jpg'.format(t), image)
			print("ban ",t)
			t = t + 1

	del(camera)


if __name__ == "__main__":
	src = 0;
	if len(sys.argv) > 1:
		src = int(sys.argv[1])
	print(src)
	main(src)
