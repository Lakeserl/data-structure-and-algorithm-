# I have 5 methods to solve this 
# Method 1: Using reversed() function
arr_input = input("Enter the elements of the array separated by space: ")
arr = list(map(int, arr_input.split()))
reversed_array = list(reversed(arr))
print("Reversed Array (Method 1):", reversed_array)

# Method 2: Using reversed() function with array
import array
arr_input = input("Enter the elements of the array separated by space: ")
arr = array.array('i', map(int, arr_input.split()))
reversed_array = array.array(arr.typecode, reversed(arr))
print("Reversed Array (Method 2):", list(reversed_array))

# Method 3: Using slicing
arr_input = input("Enter the elements of the array separated by space: ")
arr = list(map(int, arr_input.split()))
reversed_array = arr[::-1]
print("Reversed Array (Method 3):", reversed_array)

# Method 4: Using reversed() function with numpy array
import numpy as np
arr_input = input("Enter the elements of the array separated by space: ")
arr = np.array(list(map(int, arr_input.split())))
reversed_array = np.flip(arr)
print("Reversed Array (Method 4):", reversed_array)

# Method 5: Using reverse() method (in-place reversal)
arr_input = input("Enter the elements of the array separated by space: ")
arr = list(map(int, arr_input.split()))
arr.reverse()
reversed_array = arr
print("Reversed Array (Method 5):", reversed_array)
