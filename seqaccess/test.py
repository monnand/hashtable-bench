import datetime
import sys

def seq_get_dict_benchmark(n):
    a = {}

    for i in xrange(n):
        key = "%09d" % i
        a[key] = i

    s = 0

    start = datetime.datetime.now()
    for key in a.keys():
        s += a[key]
    duration = datetime.datetime.now() - start

    print "Dict Seq. Access. N =", \
            n, ": ", duration.total_seconds() * 1e6/n, "us/op"

if __name__ == "__main__":
    nr_elems = 10
    if len(sys.argv) > 1:
        nr_elems = int(sys.argv[1])
    seq_get_dict_benchmark(nr_elems)
