package main

import (
	"fmt"
)

// func insertionSort(arr []int) []int {
// 	for i := 1; i < len(arr); i++ {
// 		key := arr[i]
// 		j := i - 1

// 		for j >= 0 && arr[j] > key {
// 			arr[j+1] = arr[j]
// 			j--
// 		}

// 		arr[j+1] = key
// 	}

// 	return arr
// }

// func selectionSort(arr []int) []int {
// 	n := len(arr)
// 	for i := 0; i < n-1; i++ {
// 		minIndex := i
// 		for j := i + 1; j < n; j++ {
// 			if arr[minIndex] > arr[j] {
// 				minIndex = j
// 			}
// 		}
// 		arr[i], arr[minIndex] = arr[minIndex], arr[i]
// 	}
// 	return arr
// }

// func bubbleSort(arr []int) []int {
// 	n := len(arr)
// 	swapped := false
// 	for i := 0; i < n-1; i++ {
// 		for j := 0; j < n-i-1; j++ {
// 			if arr[j] > arr[j+1] {
// 				arr[j], arr[j+1] = arr[j+1], arr[j]
// 				swapped = true
// 			}
// 		}
// 		if !swapped {
// 			return arr
// 		}
// 	}

// 	return arr
// }

// /

func merge(arr []int, low int, mid int, high int) {
	left := low
	right := mid + 1
	temp := make([]int, 0)
	for left <= mid && right <= high {
		if arr[left] < arr[right] {
			temp = append(temp, arr[left])
			left++
		} else {
			temp = append(temp, arr[right])
			right++
		}
	}
	for left <= mid {
		temp = append(temp, arr[left])
		left++
	}
	for right <= high {
		temp = append(temp, arr[right])
		right++
	}

	for i := 0; i < len(temp); i++ {
		arr[low+i] = temp[i]
	}
}

func mergeSort(arr []int, low int, high int) []int {
	if low >= high {
		return arr
	}
	mid := (low + high) / 2
	mergeSort(arr, low, mid)
	mergeSort(arr, mid+1, high)
	merge(arr, low, mid, high)
	return arr
}

func main() {
	arr := []int{1, 4, 2, 3, 4, 2, 5}
	// result := insertionSort(arr)
	// result := selectionSort(arr)
	// result := bubbleSort(arr)
	result := mergeSort(arr, 0, len(arr)-1)

	for _, val := range result {
		fmt.Print(val, " ")
	}

}
