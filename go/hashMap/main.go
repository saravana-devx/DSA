// package main

// // func FindNumber(n int, arr []int) int {
// // 	count := 0
// // 	for _, value := range arr {
// // 		if value == n {
// // 			count++
// // 		}
// // 	}
// // 	return count
// // }

// func FindNumber(n int, arr []int) int {

// 	// pre computation using hashMap
// 	mp := make(map[int]int)
// 	for _, num := range arr {
// 		mp[num]++
// 	}

// 	return mp[n]
// }

// func main() {
// 	arr := []int{4, 2, 3, 4, 2, 4, 5}
// 	n := 4
// 	ans := FindNumber(n, arr)
// 	println(ans)
// }

package main

import (
	"fmt"
)

func main() {
	scores := make(map[string]int)

	scores["alice"] = 95
	scores["bob"] = 84
	scores["carol"] = 91

	fmt.Println(scores["alice"])

	val, ok := scores["bob"]
	if ok {
		fmt.Println("bob : ", val)
	}

	delete(scores, "bob")

	for key, val := range scores {
		fmt.Println(key, "->", val)
	}
}
