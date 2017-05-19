import sys
import math



def main():
    sys.stdin.readline()

    for line in sys.stdin:
        vars = line.split()

        v     = float(vars[0])
        theta = float(vars[1])
        x     = float(vars[2])
        h1    = float(vars[3])
        h2    = float(vars[4])

        h1 += 1
        h2 -= 1

        theta = math.radians(theta)
        t = x / (v * math.cos(theta))
        y = (v * t * math.sin(theta)) - (.5 * 9.81 * (t**2))

        if y > h1 and y < h2:
            print 'Safe'
        else:
            print 'Not Safe'



""" Launch main """
if __name__ == '__main__':
    main()
