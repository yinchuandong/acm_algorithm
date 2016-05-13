def isTrianglable(points):
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


if __name__ == '__main__':
    points = []
    points.append([0, 1])
    points.append([0, -1])
    points.append([1, 0.5])
    points.append([2, 1])
    points.append([2, -1])
    print isTrianglable(points)
