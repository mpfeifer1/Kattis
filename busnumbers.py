import sys

def group(vals):
    run = []
    result = [run]
    expect = None

    for v in vals:
        if (v == expect) or (expect is None):
            run.append(v)
        else:
            run = [v]
            result.append(run)
        expect = v + 1
    return result

def main():
    n = int(raw_input())

    for line in sys.stdin:
        nums = map(int, line.split())

    nums.sort()
    nums = group(nums)

    for i in nums:
        if(len(i) > 2):
            print str(i[0]) + '-' + str(i[-1]),
        else:
            for j in i:
                print str(j),


if __name__ == '__main__':
    main()
