import threading
import os

MAX_THREADS = os.cpu_count()

def save(arr):
    f = open("resultPython.txt", "w")

    cuantity = 1000000

    limitedSelection = int(len(arr) / cuantity)

    for i in range(0, cuantity):
        f.write(f"{i * limitedSelection} {arr[i * limitedSelection]}\n")
    f.close()

def work(startIndex, endIndex, smallnumber, diferenceByPrecission, arr):
	for i in range(startIndex, endIndex):
		arr[i] = smallnumber + (diferenceByPrecission * (i+1))

def interpolate(x, y, precission):
	toreturn = [] * precission

	for i in range(0, precission):
		toreturn.append(0)

	smallnumber = x
	diference = y - x

	if x > y:
		smallnumber = y
		diference = x - y

	diferenceByPrecission = diference / (precission+1)

	if precission < MAX_THREADS:
		work(0, precission, smallnumber, diferenceByPrecission, toreturn)
	else:
		numberToAddToIndex = precission / MAX_THREADS
		threads = []
		
		for i in range(0, MAX_THREADS):
			thread = threading.Thread(target=work, args=(int(i*numberToAddToIndex), int((i+1)*numberToAddToIndex), smallnumber, diferenceByPrecission, toreturn))
			threads.append(thread)
			thread.start()

		for thread in threads:
			thread.join()

	return toreturn

result = interpolate(0, 1000, 450000000)

save(result)
