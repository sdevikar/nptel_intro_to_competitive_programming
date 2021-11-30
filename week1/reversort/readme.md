# Reversort

## Algorithm

This is a sorting algorithm where we achieve sorting with reversing subarrays within an array. In that sense, this is a divide and conquer algorithm. The logic is as follows:

- Loop over the array from the first to the second last element : this would be your index `i`
- with `i` as your starting index, find the minimum element position `k`, between and including `i` and `length-1`
- with `array[i:k]` as your subarray, reverse `array[i:k]`

## Examples

In these examples, we define cost as the size of subarray that needs to be reversed

### Example 1

In this example, each subarray size turns out to be > 1. This turns out to be the case because after reversing the subarray, none of the remaining element fall into their rightful position.

```cpp
input = 2,4,3,1
n = 3
so, i = 0,1,2

```

| i   | input   | result  | explanation                                                                      | cost |
| --- | ------- | ------- | -------------------------------------------------------------------------------- | ---- |
| 0   | 2,4,3,1 | 1,3,4,2 | i = 0, start = 2, end = min = 1. subarray = 2,4,3,1. reverted subarray = 1,3,4,2 | 4    |
| 1   | 1,3,4,2 | 1,2,4,3 | i = 1, start = 3, end = min = 2. subarray = 3,4,2. reverted subarray = 2,4 ,3    | 3    |
| 2   | 1,2,4,3 | 1,2,3,4 | i = 2, start = 4, end = min = 3. subarray = 4,3. reverted subarray = 3,4         | 2    |

Total cost = 4 + 3 + 2 = 9

### Example 2

In this example, one reverse operation results in one of the elements to automatically fall into its rightful position (see i = 1)

```cpp
input = 2,1,4,3
n = 3
so, i = 0,1,2

```

| i   | input   | result  | explanation                                                                                    | cost |
| --- | ------- | ------- | ---------------------------------------------------------------------------------------------- | ---- |
| 0   | 2,1,4,3 | 1,2,4,3 | i = 0, start = 2, end = min = 1. subarray = 2,1. reverted subarray = 1,2                       | 2    |
| 1   | 1,2,4,3 | 1,2,4,3 | i = 1, start = 2, end = min = 2. subarray = 2. reverted subarray = 2. Note the subarray size=1 | 1    |
| 2   | 1,2,4,3 | 1,2,3,4 | i = 2, start = 4, end = min = 3. subarray = 4,3. reverted subarray = 3,4                       | 2    |

Total cost = 2 + 1 + 2 = 5

### Example 3

For this algorithm, this example will be counted as nearly sorted input. See why below.

```cpp
input = 4,3,2,1
n = 3
so, i = 0,1,2

```

| i   | input   | result  | explanation                                                                      | cost |
| --- | ------- | ------- | -------------------------------------------------------------------------------- | ---- |
| 0   | 4,3,2,1 | 1,2,3,4 | i = 0, start = 4, end = min = 1. subarray = 4,3,2,1. reverted subarray = 1,2,3,4 | 4    |
| 1   | 1,2,3,4 | 1,2,3,4 | i = 1, start = 2 end = min = 2. subarray = 2. reverted subarray = 2              | 1    |
| 2   | 1,2,3,4 | 1,2,3,4 | i = 2, start = 3, end = min = 3. subarray = 3. reverted subarray = 3             | 1    |

Total cost = 4 + 1 + 1 = 6

### Example 4

An actual sorted array

```cpp
input = 1,2,3,4
n = 3
so, i = 0,1,2

```

| i   | input   | result  | explanation                                                                | cost |
| --- | ------- | ------- | -------------------------------------------------------------------------- | ---- |
| 0   | 1,2,3,4 | 1,2,3,4 | i = 0, start = 1, end = min = 1. subarray = 1,2,3,4. reverted subarray = 1 | 1    |
| 1   | 1,2,3,4 | 1,2,3,4 | i = 1, start = 2 end = min = 2. subarray = 2. reverted subarray = 2        | 1    |
| 2   | 1,2,3,4 | 1,2,3,4 | i = 2, start = 3, end = min = 3. subarray = 3. reverted subarray = 3       | 1    |

Total cost = 1 + 1 + 1 = 3

## Further discussion

- In essence, we're moving the minimum element to its correct position
- Could we have just swapped the ith element with minimum element? Maybe. But this algorithm is probably designed for mostly sorted array or an array that is sorted in clusters
- The cost incurred for sorting different permutations shows that:
  - a minimum cost of O(n) will be incurred regardless, even for a fully sorted array since there's no check that checks if array is already sorted
  - maximum cost will be incurred when we'd have to reverse the remaining subarray at each iteration. See example#1 for this scenario. The cost in this case reduces by 1 for each iteration. So, the cost will be = `n + (n-1) + (n-2) + .... + (n - (n- 2))`. This is the same as the sum of first n natural numbers minus 1. i.e. `n(n-1)/2 - 1`. Either way, the cost is `O(n^2)`

### Maximum cost for sorting

The question is, is there a way to come up with an array that would incur maximum cost for reversing?

Since we know the pattern, it is possible to work the array backwards:

```cpp

// for odd number of elements:
1 2 3 4 5 // this is the sorted array and we must've reached to this point by reversing the last two elements. so (4,5) -> (5,4)
1 2 3 5 4 // similarly, we must've arrived here by reversing last 3 element subarray. so (3,5,4) -> (4,5,3)
1 2 4 5 3 // we got here by reversing last 4 elements. so (2,4,5,3) -> (3,5,4,2)
1 3 5 4 2 // we got here by reversing all elements. so, (1,3,5,4,2) -> (2,4,5,3,1)
2 4 5 3 1
```

```cpp

// for even number of elements

1 2 3 4
1 2 4 3
1 3 4 2
2 4 3 1
```

Observation of the characteristics:

- min element is at the end of array
- second min is at the start of array
- third min is towards the right end
- fourth min is towards the left

So, if we had to arrange a random set of numbers, so a maximum cost would incur for sorting it with this algorithm, we'd distribute the consecutive minimums with this logic. i.e. until we're done with the numbers, we keep sticking them at either end of the slot moving towards the middle.
We could have two pointers, one going from left to right and the other from right to left and we stick the numbers until the pointers meet. 
