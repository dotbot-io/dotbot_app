import dotbot_ros
from std_msgs.msg import Float32
from gpiozero import LED

import sys

from math import sin

class Node(dotbot_ros.DotbotNode):
    node_name = 'sin_gen'
    
    def setup(self):
        self.loop_rate = dotbot_ros.Rate(10)
        self.t = 0.0
        self.pub_sin = dotbot_ros.Publisher('sin', Float32)

    def loop(self):
        self.pub_sin.publish(sin(self.t))
        self.t += 0.1
        print self.t
        sys.stdout.flush()