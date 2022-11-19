# coding:utf-8
# import step, fix the "Module ‘sys‘ Has No Attribute ‘argv‘" bug.
import sys
sys.argv=['']
# self-define python search path to local directory.
sys.path.append("../python-2.7/lib/site-packages")

from matplotlib import pyplot as plt
import math

def paint(data): 
    time = []
    tx = []
    ty = []
    tz = []
    
    plt.ion()#activate interaction modeul and do not block code 
    plt.title('tx-ty')
    plt.xlabel('tx')
    plt.ylabel('tz')
    for i in range(len(data)):
        plt.clf() #clear previous paint img
        temp_data = data[i].split(' ')
        time.append(float(temp_data[0]))
        tx.append(float(temp_data[1]))
        ty.append(float(temp_data[2]))
        tz.append(float(temp_data[3]))        

    plt.plot(tx, ty, c='r')   
    plt.pause(0.000001)#unit is second 
    plt.ioff()    
    #plt.savefig('tx-ty')
    
 
#在if name == 'main':下的代码只有在文件作为脚本直接执行才会被执行，而import到其他脚本中是不会被执行的。
if __name__ == "__main__":
    paint()
