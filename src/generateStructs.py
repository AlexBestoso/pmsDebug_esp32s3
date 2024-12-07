import re
def wout(target, data):
	with open(target, 'w') as f:
		for d in data:
			f.write(d)
def prepItems(target):
	ret = []
	ctx = 0
	with open(target, 'r') as f:
		for line in f:
			if ctx == 0 and re.match('^Register .*$', line):
				ret.append(line)
				ctx = 1
			elif ctx == 1 and not re.match('^Reset$', line):
				ret.append(line)
			elif ctx == 1 and re.match('^Reset$', line):
				ret.append(line+'\n')
				ctx = 0	
	wout(target, ret)

def isolateItems(target):
	ret = []
	retG = ""
	ctx = 0
	with open(target, 'r') as f:
		for line in f:
			if re.match('^$', line):
				ret.append(retG)
				retG = ''
			else:
				retG = retG + line
	return ret

def getStructName(item):
	for line in item.split('\n'):
		ret = re.sub('^register 15.*\. ', '', line)
		ret = re.sub('_reg.*$', '_reg', ret)
		ret = re.sub('\n', '', ret)
		ret = re.sub('\r', '', ret)
		return ret

def getBaseAddress(item):
	for line in item.split('\n'):
		ret = re.sub('^register .*_reg \(', '', line)
		ret = re.sub('\)', '', ret)
		ret = re.sub('n: .*\(', '', ret)
		ret = re.sub(' .*$', '', ret)
		ret = re.sub('\n', '', ret)
		ret = re.sub('\r', '', ret)
		return ret

def craftStructItems(item):
	ctx = 0
	ret = []
	retG = ""
	skipper = 0

	name = ""
	defval = ""
	posX = ""
	posY = ""
	for line in item.split('\n'):
		if skipper != 0:
			skipper = skipper - 1
		elif ctx == 0:
			ctx = 1 # we can ignore the first 
		elif ctx == 1 and re.match('^.*reserved.*$', line):
			skipper = 2 # reserved field, ignore the next two lines
		elif ctx == 1 and re.match('^pms.*$', line) or re.match('^apb.*$', line):
			name = re.sub('\n', '', line)
			name = re.sub('\r', '', name)
			ctx = 2
		elif ctx == 2:
			defval = re.sub('\n', '', line)
			defval = re.sub('\r', '', line)
			ctx = 3
		elif ctx == 3 and re.match('^\d*\s\d*$', line): # non-boolean
			posY = re.sub(' \d*$', '', line)
			posY = re.sub('\r', '', posY)
			posY = re.sub('\n', '', posY)
		
			posX = re.sub('^\d* ', '', line)
			posX = re.sub('\r', '', posX)
			posX = re.sub('\n', '', posX)
			# build a uin32_t field
			retG = f"\tuint32_t {name} = {defval};\n\tint {name}_x = {posX};\n\tint {name}_y = {posY};\n"
			ret.append(retG)
			ctx = 1
		elif ctx == 3: # boolean
			posX = re.sub('\r', '', line)
			posX = re.sub('\n', '', posX)
			
			# build a bool field
			if defval == '0':
				defval = 'false'
			else:
				defval = 'true'

			retG = f"\tbool {name} = {defval};\n\tint {name}_pos = {posX};\n"
			ret.append(retG)

			ctx = 1
	return ret

t = "PmsDebug.struct.h"
#prepItems(t)
out = []
ctx = 0
items = isolateItems(t)
for i in items:
	structName = getStructName(i)
	out.append(f'struct {structName}'+'{\n\tuint32_t val = 0;\n')
	baseAddr = getBaseAddress(i)
	out.append(f'\tuint16_t base = {baseAddr};\n\n')
	structVars = craftStructItems(i)
	for sv in structVars:
		out.append(sv+'\n')
	out.append('};\n')
wout(t, out)
