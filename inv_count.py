def count_inversions_brute_force(course_codes):
    inversion_count = 0
    n = len(course_codes)

    # Compare every pair of course codes
    for i in range(n):
        for j in range(i + 1, n):
            if course_codes[i] > course_codes[j]:
                inversion_count += 1

    return inversion_count


def merge_and_count(arr, temp_arr, left, mid, right):
    i = left  # Starting index for left subarray
    j = mid + 1  # Starting index for right subarray
    k = left  # Starting index to be sorted
    inv_count = 0

    # Conditions are checked to ensure that i doesn't exceed mid and j doesn't exceed right
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp_arr[k] = arr[i]
            i += 1
        else:
            # There are mid - i inversions, because all elements left to i in the left subarray
            temp_arr[k] = arr[j]
            inv_count += (mid - i + 1)
            j += 1
        k += 1

    # Copy the remaining elements of the left subarray, if any
    while i <= mid:
        temp_arr[k] = arr[i]
        i += 1
        k += 1

    # Copy the remaining elements of the right subarray, if any
    while j <= right:
        temp_arr[k] = arr[j]
        j += 1
        k += 1

    # Copy the sorted subarray into the original array
    for i in range(left, right + 1):
        arr[i] = temp_arr[i]

    return inv_count


def merge_sort_and_count(arr, temp_arr, left, right):
    inv_count = 0
    if left < right:
        mid = (left + right) // 2

        inv_count += merge_sort_and_count(arr, temp_arr, left, mid)
        inv_count += merge_sort_and_count(arr, temp_arr, mid + 1, right)
        inv_count += merge_and_count(arr, temp_arr, left, mid, right)

    return inv_count


def count_inversions_merge_sort(course_codes):
    temp_arr = [0] * len(course_codes)
    return merge_sort_and_count(course_codes, temp_arr, 0, len(course_codes) - 1)


# Test cases for inversion counting

# Positive Test Cases
positive_test_cases = [
    (["301224510", "301224511T", "301224610"], 0),
    (["301237210", "301237211T", "301261210"], 0),
    (["301237610", "301237611T", "301237210"], 2),
]

print("Positive Test Cases:")
for i, (course_codes, expected) in enumerate(positive_test_cases):
    brute_force_count = count_inversions_brute_force(course_codes)
    merge_sort_count = count_inversions_merge_sort(course_codes[:])  # Use a copy to avoid mutation
    print(f"Test Case {i + 1}: Expected: {expected}, Brute Force Count: {brute_force_count}, Merge Sort Count: {merge_sort_count}")
