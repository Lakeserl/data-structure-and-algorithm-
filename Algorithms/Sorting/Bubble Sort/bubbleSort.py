def bubble_sort(list1):
    n = len(list1)
    # Duyệt toàn bộ phần tử trong danh sách
    while n > 1:
        # Gắn một biến để kiểm tra hàm có cần hoán đổi trong lần lặp này không
        swapped = False
        for i in range(n - 1):
            if list1[i] > list1[i + 1]:
                # Hoản đổi lại nếu sai thứ tự
                list1[i], list1[i + 1] = list1[i + 1], list1[i]
                # Set swapped = True nếu đúng
                swapped = True
        # Giảm kích thước của list cần duyệt trong lần lặp tiếp theo
        n -= 1
        # Nếu không thực hiện hoán đổi trong lần lặp này thì danh sách đã được sắp xếp
        if not swapped:
            break
    return list1

list1 = [4, 5, 6, 2, 1, 8, 3]
print("The unsorted list is: ", list1)
# Call hàm sắp xếp Bubble Sort
print("The sorted list is: ", bubble_sort(list1))
