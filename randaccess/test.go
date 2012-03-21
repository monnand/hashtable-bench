package main

import (
	"fmt"
	"runtime"
	"time"
	"math/rand"
	"flag"
)

func RandGetMapBenchmark(N int, gc bool) {
	if gc {
		runtime.GC()
	}
	rand.Seed(time.Now().UnixNano())
	a := make(map[string]int, N)
	keys := make([]string, N)
	seq := make([]string, N)

	// Insert numbers
	for i := 0; i < N; i++ {
		key := fmt.Sprintf("%09d", i)
		a[key] = i
		keys[i] = key
	}

	seq_idx := rand.Perm(N)

	for i := 0; i < N; i++ {
		idx := seq_idx[i]
		seq[i] = keys[idx]
	}

	sum := 0
	start := time.Now()
	for _, key := range seq {
		sum += a[key]
	}
	duration := time.Since(start)

	fmt.Printf("Map Random Access. N = %v: %v us/op\n",
		N, duration.Seconds() * 1e6/float64(N))
}

var nrElem int

func init() {
	flag.IntVar(&nrElem, "n", 10, "Number of elements")
}

func main() {
	gc := true
	flag.Parse()
	RandGetMapBenchmark(nrElem, gc)
}

