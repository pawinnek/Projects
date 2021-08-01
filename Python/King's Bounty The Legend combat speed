import re
import glob
# from os import listdir
# from os.path import isfile, join




file_list = glob.glob(".\\*.atom")
# print(file_list)
for file_name in file_list:
    file = open(file_name)
    lines = file.readlines()
    file.close()
    x2 = []
    finalstring = ""
    for x in lines:
        z = re.search("=*\.bsa\/fr:[0-9]*:[0-9]*\n", x)
        # print(x + " : " + str(z))
        if z != None:
            x_list = x.split(":")
            as_int = int(x_list[len(x_list) - 1])
           # multiplier use wise
            as_int *= 4
            x_list[len(x_list) - 1] = as_int
            for k_val in x_list:
                if k_val == x_list[len(x_list) - 1]:
                    finalstring += str(k_val) + "\n"
                else:
                    finalstring += str(k_val) + ":"
            
            # x2.append(x)
            # print(x)
        elif x != '\n':
            # print(x)
            # x2.append(x)
            finalstring += x
    file = open(file_name, "w")
    file.write(finalstring)
    file.close() 
    

