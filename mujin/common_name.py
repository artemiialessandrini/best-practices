def digit_sum(n: int) -> int:
    return sum(int(d) for d in str(n))


def find_common(start1: int, start2: int) -> int:
    seen1 = set()
    seen2 = set()

    while True:
        # Generate for the first sequence
        if start1 in seen2:
            return start1  # Found a common number
        seen1.add(start1)
        start1 += digit_sum(start1)

        # Generate for the second sequence
        if start2 in seen1:
            return start2  # Found a common number
        seen2.add(start2)
        start2 += digit_sum(start2)

        # Optional: Limit the number of iterations to prevent infinite loops
        if len(seen1) > 10000 or len(seen2) > 10000:
            break

    return -1  # Return -1 if no common number is found


# Example usage
common_number = find_common(471, 480)
if common_number != -1:
    print("Common number:", common_number)
else:
    print("No common number found.")
