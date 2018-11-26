import pylab
import numpy as np
import matplotlib.pyplot as plt
import math

#list_of_files = [('/Users/cbartram/MagneticSimulations/pass_thru','label 1'),
list_of_files_1 = [('/Users/cbartram/Analysis_Components_Caliope/MakeAnalysisPlots/AP_EDiff.txt','label 2')]

datalist1 = [ ( pylab.loadtxt(filename), label ) for filename, label in list_of_files_1 ]
#datalist2 = [ ( pylab.loadtxt(filename), label ) for filename, label in list_of_files_2 ]
colors = ["red","Crimson"]

#x = [-27.5,-16.5,-5.5,5.5,16.5,27.5]
#x = [100.0,200.0,300.0,400.0,500.0,600.0]
#x = [0.0,50.0,100.0,150.0,200.0,250.0]
x = [25.0,75.0,125.0,175.0,225.0,275.0]
#for x in range(1,6):
for data, label in datalist1:
        pylab.scatter( x, data[:,0], label=label, color=colors[1],s=100,edgecolor='none');
        c=[3,3,3,3,3,3];
#        pylab.errorbar( data[:,0], data[:,1], yerr=data[:,1/(math.sqrt(1))], linestyle="None");
        pylab.errorbar(x, data[:,0], yerr=1/((data[:,1])**(1/2.0)), linestyle="None");
        
#pylab.legend()
#pylab.title("Magnetic Field v Position (Inside Pipe Within Magnet): 8 mm Wall Thickness")
#pylab.xlabel("Inches (from end of ruler placed inside magnet)")
#pylab.ylabel("Gauss")
pylab.show()
