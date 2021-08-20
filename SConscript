Import('rtconfig')
from building import *

src	= Glob('*.c')
group = DefineGroup('cmatrix', src, depend = ['PKG_USING_CMATRIX'])
Return('group')
