
def divide(A):
    # divide array A into 2 sub-arrays (left, right) and 1 pivot
    # this function is called log(n) times
    n = len(A)
    if n >= 3:
        m = int(n / 2)
        pvt = A[m]
        B = A[0:m]
        C = A[m + 1:]
        print pvt
        if not divide(B):
            print 'B: false'
            return False
        if not divide(C):
            print 'C: false'
            return False
        return merge(B, C, pvt)
    else:
        return True


def merge(B, C, pvt):
    # checking the area created by left array, pvt, right array
    for b in B:
        for c in C:
            if checkCoLine(b, c, pvt):
                print '1: false'
                return False
    # checking the area created by left array, pvt, left array
    if len(B) > 1:
        for b in B:
            for b1 in B:
                if b == b1:
                    continue
                if checkCoLine(b, b1, pvt):
                    print '2: false'
                    return False
    # checking the area created by right array, pvt, left array
    if len(C) > 1:
        for c in C:
            for c1 in C:
                if c == c1:
                    continue
                if checkCoLine(c, c1, pvt):
                    print '3: false'
                    return False
    return True


def checkCoLine(p1, p2, p3):
    # check if p1, p2, p3 is in a same line
    # if p1[0] == 0 and p1[1] == -1.1:
        # print (p1[1] - p2[1]) * (p1[0] - p3[0]) - (p1[1] - p3[1]) * (p1[0] - p2[0])
    return (p1[1] - p2[1]) * (p1[0] - p3[0]) == (p1[1] - p3[1]) * (p1[0] - p2[0])


def isTrianglable(points):
    # main function
    # sorted the points by x coordinate
    points = sorted(points, key=lambda a: a[0])
    print points
    if len(points) < 3:
        return False
    return divide(points)

if __name__ == '__main__':
    points = []
    points.append([0, 1])
    points.append([0, -1])
    points.append([1, 0.5])
    points.append([2, 1])
    points.append([2, -1])
    points.append([3, 0.2])
    points.append([4, 1])
    points.append([4, -1])
    points.append([5, 0.5])
    points.append([6, 1])
    points.append([6, -1])
    print isTrianglable(points)
