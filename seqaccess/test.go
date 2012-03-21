package main

import (
	"fmt"
	"runtime"
	"time"
	"flag"
)

func SeqGetMapBenchmark(N int, gc bool) {
	if gc {
		runtime.GC()
	}
	a := make(map[string]int, N)

	// Insert numbers
	for i := 0; i < N; i++ {
		key := fmt.Sprintf("%09d", i)
		a[key] = i
	}

	sum := 0
	start := time.Now()
	for  key := range a {
		sum += a[key]
	}
	duration := time.Since(start)

	fmt.Printf("Map Sequantial Access. N = %v: %v us/op\n",
		N, duration.Seconds() * 1e6/float64(N))
}

var nrElem int

func init() {
	flag.IntVar(&nrElem, "n", 10, "Number of elements")
}

func main() {
	gc := true
	flag.Parse()
	SeqGetMapBenchmark(nrElem, gc)
}

