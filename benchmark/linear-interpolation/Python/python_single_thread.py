def save(arr):
    f = open("resultPython.txt", "w")

	cuantity = 1000000

	limitedSelection = len(arr) / cuantity

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

	work(0, precission, smallnumber, diferenceByPrecission, toreturn)

	return toreturn

result = interpolate(0, 1000, 450000000)

save(result)
