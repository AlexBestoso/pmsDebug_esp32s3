import re
def wo(t, o):
	with open(t, "w") as f:
		for line in o:
			f.write(line)
def getFuncs(target):
	ret = []
	retG = ""
	ctx = 0
	with open(t, 'r') as f:
		for line in f:
			if ctx == 0 and re.match('^void .*$', line):
				retG = line
				ctx = 1
			elif ctx == 1 and re.match('^}.*$', line):
				ret.append(retG + line)
				ctx = 0
			elif ctx == 1:
				retG += line
	return ret
def getRegVal(func):
	ret = ""
	for f in func.split('\n'):
		ret = re.sub('^void .*patch_', '', f)
		ret = re.sub('\(void.*$', '', ret)
		ret = 'this->'+ret+'.val'
		break
	return ret	

# script start
t = "./tmp"
output = []
funcs = getFuncs(t)

for func in funcs:
	regVal = getRegVal(func)
	ctx = 0
	for line in func.split('\n'):
		if re.match('^void .*$', line):
			output.append(line+'\n')
wo(t, output)
