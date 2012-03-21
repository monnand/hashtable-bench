import datetime
import random
import sys

def random_get_dict_benchmark(n):
    a = {}
    seq = []

    for i in xrange(n):
        key = "%09d" % i
        a[key] = i
        seq.append(key)

    s = 0
    random.shuffle(seq)

    start = datetime.datetime.now()
    for key in seq:
        s += a[key]
    duration = datetime.datetime.now() - start

    print "Dict Random Access. N =", \
            n, ": ", duration.total_seconds() * 1e6/n, "us/op"

if __name__ == "__main__":
    nr_elems = 10
    if len(sys.argv) > 1:
        nr_elems = int(sys.argv[1])
    random_get_dict_benchmark(nr_elems)
