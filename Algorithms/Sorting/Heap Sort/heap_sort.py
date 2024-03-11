
def max_heapify(arr, n, idx):
  max, left, right = idx, 2*idx + 1, 2*idx + 2

  if left <= n and arr[left] > arr[max]:
    max = left

  if right <= n and arr[right] > arr[max]:
    max = right

  if max != idx:
    arr[idx], arr[max] = arr[max], arr[idx]

    max_heapify(arr, n, max) 

def heapsort(arr):
  n = len(arr)
  for idx in range(n//2, -1, -1):
    max_heapify(arr, n-1, idx)

  for idx in range(n-1, -1, -1):

    arr[0], arr[idx] = arr[idx], arr[0]
    
    max_heapify(arr, idx-1, 0)

if __name__ == '__main__':
    test_arr = [1, 0, 111, 634, 25, -400, 42, -69]
    print(f"Test List: {test_arr}")
    heapsort(test_arr)
    print(f"Sorted List: {test_arr}")
    
# This is not the code I write by my self