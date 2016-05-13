import heapq


def mergeKArray(*lists):
    # implemented by min heap
    h = []
    r = []
    for k, arr in enumerate(lists):
        heapq.heappush(h, (arr[0], 0, k))
    while h:
        # min is the minimum element
        # i is the index of the min in the k-th array
        # k is the index of array in the list
        min, i, k = heapq.heappop(h)
        r.append(min)
        if i < len(lists[k]) - 1:
            i += 1
            heapq.heappush(h, (lists[k][i], i, k))
    return r


def mainMergeK(*lists):
    # implemented by k-way partition
    k = len(lists)
    if k > 1:
        mid = int(k / 2)
        B = mainMergeK(*lists[0: mid])
        C = mainMergeK(*lists[mid:])
        A = merge(B, C)
        print B, ' + ', C, ' = ', A
        return A
    return lists[0]


def merge(B, C):
    A = []
    p = len(B)
    q = len(C)
    i = 0
    j = 0
    while i < p and j < q:
        if B[i] <= C[j]:
            A.append(B[i])
            i += 1
        else:
            A.append(C[j])
            j += 1
    if i == p:
        for c in C[j:]:
            A.append(c)
    else:
        for b in B[i:]:
            A.append(b)
    return A


if __name__ == '__main__':
    # x = mergeKArray([1, 3, 5], [2, 4, 6], [7, 8, 10], [9])
    # print x
    x = mainMergeK([1, 3, 5], [2, 4, 6], [7, 8, 10], [9], )
    print x
