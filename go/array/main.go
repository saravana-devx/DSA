package main

// For-Loop Approach -> TC: O(n), SC: O(1)
func PrintFibonacci(n int) {
	a := 0
	b := 1
	print(a, "\n")
	print(b, "\n")
	for i := 3; i <= n; i++ {
		c := a + b
		print(c, "\n")
		a = b
		b = c
	}
}

// Recursive Approach -> TC: O(2^n), SC: O(n)(2^n) + O(n)
func UsingRecursive(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	return UsingRecursive(n-1) + UsingRecursive(n-2)
}

// Fibonacci sequence
func main() {
	n := 10
	// PrintFibonacci(n)
	ans := UsingRecursive(n)
	println(ans)
}
