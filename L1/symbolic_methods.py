'''
Symbolic methods introduction
'''

import sympy
from sympy.utilities.codegen import codegen

x, y, t = sympy.symbols('x y t')

beta = sympy.exp(-(x*t)**2/6*(t**y)* (t-2*x*y))
dbeta_dx = beta.diff(x)

code = codegen(\
    ('dbeta_dx', dbeta_dx), 
    'C', 
    'dbeta_dx',
    project='symbolic_methods',
    standard='C99',
    to_files=True)
