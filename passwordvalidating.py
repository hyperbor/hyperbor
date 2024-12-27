def alpha(string):
	alpha = "qwertyuiopasdfghjklzxcvbnm"
	counter_lower = 0 
	counter_upper = 0

	for i in alpha:
		if string.count(i) != 0  :
			counter_lower += 1
	
	for i in alpha:
		if string.count(i.upper()) != 0:
			counter_upper += 1

	if counter_lower != 0 and counter_upper != 0 :
		return True
	else:
		return False


def numbers(string):
	number = "1234567890"

	counter_num = 0
	
	for i in number :
		if string.count(i) != 0:
			counter_num += 1

	if counter_num != 0:
		return True
	else:
		return False


def signs(string):
	sign = "@#$%&"
	
	counter_sign = 0

	for i in sign:
		if string.count(i) != 0 :
			counter_sign += 1

	if counter_sign != 0:
		return True
	else:
		return False


def len_check(string):
	if len(string) >= 8 and len(string) <= 16 :
		return True
	else :
		return False


def validity(string):
	if alpha(string) and numbers(string) and signs(string) and len_check(string) :
		print("VALID")
	else:
		print("INVALID!")





password = input("enter a password : ")
validity(password)
