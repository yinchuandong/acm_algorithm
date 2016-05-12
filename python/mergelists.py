import heapq


def mergeKArray(*lists):
    h = []
    r = []
    for k, arr in enumerate(lists):
        heapq.heappush(h, (arr[0], 0, k))
    while h:
        # min is the element
        # i is the index of element in k-th array
        # k is the index of array
        min, i, k = heapq.heappop(h)
        r.append(min)
        if i < len(lists[k]) - 1:
            i += 1
            heapq.heappush(h, (lists[k][i], i, k))
    return r

if __name__ == '__main__':
    x = mergeKArray([1, 3, 5], [2, 4, 6], [7, 8, 10], [9])
    print x
