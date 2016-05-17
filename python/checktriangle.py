import math


def isTrianglable2(points):
    for p1 in points:
        slopeArr = []
        nonSlopePoints = 0
        for p2 in points:
            if p1 == p2:
                continue
            if p1[0] == p2[0]:
                # when slope doesn't exist
                nonSlopePoints += 1
                if nonSlopePoints == 2:
                    return False
            else:
                slope = (p1[1] - p2[1]) / (p1[0] - p2[0])
                slopeArr.append(slope)
        slopeArr = sorted(slopeArr)
        preSlope = slopeArr[0]
        for slope in slopeArr[1:]:
            if slope == preSlope:
                return False
            preSlope = slope
    return True


def isTrianglable(points):
    vector1 = (1, 0)
    for p1 in points:
        coAngleArr = []
        for p2 in points:
            if p1 == p2:
                continue
            vector2 = (p2[0] - p1[0], p2[1] - p1[1])
            coAngle = angle(vector1, vector2)
            coAngle = coAngle + math.pi if coAngle < 0 else coAngle
            coAngleArr.append(coAngle)
        coAngleArr = sorted(coAngleArr)
        print coAngleArr
        preAngle = coAngleArr[0]
        for slope in coAngleArr[1:]:
            if slope == preAngle:
                return False
            preAngle = slope
    return True


def angle(v1, v2):
    # angle from -pi to pi
    x1, y1 = v1
    x2, y2 = v2
    dot = x1 * x2 + y1 * y2  # dot product
    det = x1 * y2 - y1 * x2  # determinant
    angle = math.atan2(det, dot)  # atan2(y, x) or atan2(sin, cos)
    return angle

if __name__ == '__main__':
    points = []
    points.append((0, 1))
    points.append((0, -1))
    points.append((1, 0.5))
    points.append((2, 1))
    points.append((2, -1))
    print isTrianglable(points)
