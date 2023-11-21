#!/usr/bin/env python3

import random
max = 100
for i in range(max):
    if i != max-1:
        print(random.randrange(100),end=' ')
    else:
        print(random.randrange(100),end='\n')
