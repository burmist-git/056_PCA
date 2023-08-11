from scipy.io import loadmat
import numpy as np
import pickle as pkl
import pandas as pd
import time
import subprocess
import sys
#
#bird_small.mat  ex7data1.mat  ex7data2.mat  ex7faces.mat  token.mat
#48K	mat/bird_small.mat
#4.0K	mat/ex7data1.mat
#8.0K	mat/ex7data2.mat
#11M	mat/ex7faces.mat
#4.0K	mat/token.mat
annots = loadmat('./mat/ex7faces.mat')
print(annots)
print(type(annots))
print(type(annots['X']))
print((annots['X'].shape))
#
df=pd.DataFrame(annots['X'])
#csvfileout=str(fin[:-3]+'csv')
#print(csvfileout)
df.to_csv('ex7faces.cvs',sep=' ',header=False)
#print(df)
