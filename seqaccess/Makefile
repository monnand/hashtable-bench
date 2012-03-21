all: seqaccess HashMapBench.class a.out
seqaccess: test.go
	go build
HashMapBench.class: HashMapBench.java
	javac HashMapBench.java
a.out: test.cpp
	g++ -g -std=c++0x test.cpp

.PHONY: go
