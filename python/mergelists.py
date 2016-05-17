import heapq


def mergeKArray(*lists):
    # implemented by min heap
    heap = []
    result = []
    for row_id, arr in enumerate(lists):
        heapq.heappush(heap, (arr[0], row_id, 0))
    while heap:
        # min is the minimum element
        # col is the index of the min in the k-th array
        # row is the index of array in the list
        min, row_id, col_id = heapq.heappop(heap)
        result.append(min)
        if col_id < len(lists[row_id]) - 1:
            col_id += 1
            heapq.heappush(heap, (lists[row_id][col_id], row_id, col_id))
    return result


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
    x = mergeKArray([1, 3, 5], [2, 4, 6], [7, 8, 10], [9])
    print x
    # x = mainMergeK([1, 3, 5], [2, 4, 6], [7, 8, 10], [9], )
    # print x
