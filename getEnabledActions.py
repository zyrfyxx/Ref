import sys
sys.path.append('/home/kokaze/LTLMoP-py3/')


import random
import project

proj = project.Project()
proj.loadProject('/home/kokaze/LTLMoP/src/Control/Control.spec')
region_name = 'r1'
init_region = None
for i in proj.rfi.regions:
    if i.name == region_name:
        init_region = i


enabled_actions = []

for item in proj.enabled_actuators:
    enabled_actions.append(item)



def getEnabledActions():
    global enabled_actions
    print(enabled_actions)
    return enabled_actions