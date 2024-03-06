s = input()
maxlen = 0

texts = s.split(",")

for text in texts:
	for word in text.split():
		if len(word) > maxlen:
			maxlen = len(word)

maxlen = maxlen * 3

# for text in texts:
#   arr = text.split()
# 	for i in range(len(arr)-1):
# 		if curlen + len(arr[i]) > maxlen:
#       outtext += "\n"
#       curlen = 0
#     outtext += arr[i]
#     curlen += len(arr[i])

#   if curlen + 1 + len(arr[len(arr)-1]) > maxlen:

curword = ""
outtext = ""
curlen = 0
for ch in s:
  if ch == ",":
    if curlen + len(curword) + 1 > maxlen:
      outtext += "\n"
      outtext += curword
      outtext += ", "
      curlen = len(curlen) + 2
      curword = ""
      continue
    elif curlen + len(curword) + 1 == maxlen:
      outtext += curword
      outtext += ",\n"
      curlen = 0
      continue
    else:
      outtext += ", "

  



    

