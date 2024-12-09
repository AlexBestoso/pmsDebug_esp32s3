import re
def wo(t, o):
	with open(t, "w") as f:
		for line in o:
			f.write(line)
def isolateStructs(target):
	ret = []
	retG = ""
	ctx = 0
	with open(target, "r") as f:
		for line in f:
			if ctx == 0 and re.match('^struct .*$', line):
				retG = line
				ctx = 1
			elif ctx == 1 and not re.match('^};', line):
				retG = retG + line
			elif ctx == 1 and re.match('^};', line):
				ctx = 0
				ret.append(retG+line)
	return ret
def getInstanceName(struct):
	name = ""
	for line in struct.split('\n'):
		name = re.sub('^struct pms_', '', line)
		name = re.sub('^struct apb_', '', name)
		name = re.sub('_reg{.*$', '', name)
		name = re.sub('\n', '', name)
		name = re.sub('\r', '', name)
		return name
	return name
def getRegType(struct):
	for line in struct.split('\n'):
		if re.match('^struct pms_', line):
			return 'true'
		else:

			return 'false'
def buildInitBody(struct, varType, thisVar):
	ret = []
	retG = ""
	ctx = 0
	varName = ""
	baseVal = ""

	ret.append('\tuint16_t base = '+thisVar+'.base;\n')
	ret.append('\t'+thisVar+'.val = this->regRead('+varType+', base);\n')
	for line in struct.split('\n'):
		if ctx == 0 and re.match('^.*uint16_t base =.*$', line):
			ctx = 1
		elif ctx == 1 and re.match('^.*uint32_t .*$', line):
			varName = re.sub('^.*uint32_t ', '', line)
			varName = re.sub(' = .*$', '', varName)
			retG = "\t"+thisVar+"."+varName+' = this->regGet(\n\t\t'+thisVar+'.val,\n\t\t'+thisVar+"."+varName+'_x,\n\t\t'+thisVar+"."+varName+'_y\n\t);\n'
			ret.append(retG)
		elif ctx == 1 and re.match('^.*bool .*$', line):
			varName = re.sub('^.*bool ', '', line)
			varName = re.sub(' = .*$', '', varName)
			retG = "\t"+thisVar+"."+varName+' = this->regGet(\n\t\t'+thisVar+'.val,\n\t\t'+thisVar+"."+varName+'_pos,\n\t);\n'
			ret.append(retG)
	return ret

# script start
t = "./tmp"
output = []

structList = isolateStructs(t)
for s in structList:
	varName = getInstanceName(s)
	varType = getRegType(s)
	thisVar = f"this->{varName}"
	funcDeclar = f"void init_{varName}(void)"
	funcDeclar += "{\n"
	output.append(funcDeclar)
	body = buildInitBody(s, varType, thisVar)
	for b in body:
		output.append(b)
	output.append('}\n')

wo(t, output)
