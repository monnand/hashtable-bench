#include <list>
#include <unordered_map>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void shuffle(char **a, int n)
{
	int i, c;
	char *t;
	srand(time(NULL));

	for (i = 0; i < n - 1; i++) {
		c = rand() / (RAND_MAX/(n - i) + 1);
		t = a[i];
		a[i] = a[i + c];
		a[i + c] = t;
	}
}

void random_get_map_benchmark(int N)
{
	unordered_map <string, int> a;

	char **seq;
	int i;
	int sum;
	char *buf;
	struct timeval start, end;
	long seconds, useconds;
	float mtime;

	seq = (char **)malloc(sizeof(char *) * N);
	memset(seq, 0, sizeof(char *) * N);

	for (i = 0; i < N; i++) {
		buf = (char *)malloc(10);
		memset(buf, 0, 10);
		snprintf(buf, 10, "%09d", i);
		a[buf] = i;
		seq[i] = buf;
	}

	shuffle(seq, N);

    sum = 0;
    gettimeofday(&start, NULL);
	for (i = 0; i < N; i++) {
    	sum += a[seq[i]];
    }
    gettimeofday(&end, NULL);

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = seconds * 1e6 + useconds;
    cout << "Unordered Map Random Access. N = " 
        << N << ". " << mtime/N << " us/op." << endl; 

	for (i = 0; i < N; i++) {
		free(seq[i]);
	}
	free(seq);
}

int main(int argc, char *argv[])
{
	int nr_elems = 10;
	if (argc > 1)
		nr_elems = atoi(argv[1]);
	random_get_map_benchmark(nr_elems);
	/*
    random_get_map_benchmark(100);
    random_get_map_benchmark(1000);
    random_get_map_benchmark(10000);
    random_get_map_benchmark(100000);
    random_get_map_benchmark(1000000);
    random_get_map_benchmark(10000000);
	*/
}
