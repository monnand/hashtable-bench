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

void seq_get_map_benchmark(int N)
{
	unordered_map <string, int> a;
	unordered_map <string, int>::iterator it;

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

    sum = 0;
    gettimeofday(&start, NULL);
	for (it = a.begin(); it != a.end(); it++) {
    	sum += a[it->first];
    }
    gettimeofday(&end, NULL);

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = seconds * 1e6 + useconds;
    cout << "Unordered Map Seq. Access. N = " 
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
	seq_get_map_benchmark(nr_elems);
}
