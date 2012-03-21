function run_bench
{
	for i in 10 100 1000 10000 100000 1000000 10000000
	do
		$1 ${i}
	done
}

case $1 in
	"go")
		echo "Go:"
		run_bench "./randaccess -n"
		;;
	"java")
		echo "Java:"
		run_bench "java HashMapBench"
		;;
	"cpp")
		echo "C++:"
		run_bench "./a.out"
		;;
	"python")
		echo "Python:"
		run_bench "python test.py"
esac
