def merge(array1, array2):
    merged = []

    while (array1 and array2):
        if array1[0] < array2[0]:
            merged.append(array1.pop(0))
        else:  # includes equal to case
            merged.append(array2.pop(0))

    # add remaining, if any
    merged.extend(array1)
    merged.extend(array2)

    return merged


def merge_sort(array, left, right, name):
    mid = left + (right - left) // 2
    print(name, left, mid, right)

    if (mid == left):
        return array[left:right]

    temp_left = merge_sort(array, left, mid, "L")
    temp_right = merge_sort(array, mid, right, "R")

    return merge(temp_left, temp_right)


lst = [100, 40, 00000, -85, 30, -999, 100, 25]
print(merge_sort(lst, 0, len(lst), "main"))
