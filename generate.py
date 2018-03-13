#!/usr/bin/env python
import os

from pymoca.parser import parse as parse_mo
from pymoca.backends.xml.generator import generate as gen_xml
from pymoca.backends.xml.parser import parse as parse_xml

pwd = os.path.abspath(os.curdir)
model_path = os.path.join('src', 'Ball.mo')

with open(model_path, 'r') as f:
    txt = f.read()
ast = parse_mo(txt)
m = parse_xml(gen_xml(ast, 'Ball'))
print(m)

m_ode = m.to_ode()
print(m_ode)

gen_path = os.path.join('src', 'gen')
if not os.path.exists(gen_path):
    os.mkdir(gen_path)
os.chdir(gen_path)

print('generating c code')
m_ode.create_function_f_x_rhs().generate('f_x_rhs.c')
m_ode.create_function_f_i().generate('f_i.c')
m_ode.create_function_f_J().generate('f_J.c')
m_ode.create_function_f_m().generate('f_m.c')
m_ode.create_function_f_y().generate('f_y.c')
m_ode.create_function_f_c().generate('f_c.c');
os.chdir(pwd)

print('done')
