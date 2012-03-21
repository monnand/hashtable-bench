import java.util.HashMap;
import java.util.Iterator;
import java.util.Random;

public class HashMapBench {

	public static void shuffle(String []seq) {
		Random g = new Random();
		int i, c;
		String t;

		for (i = 0; i < seq.length; i++) {
			c = g.nextInt(seq.length - i);
			t = seq[i];
			seq[i] = seq[i + c];
			seq[i + c] = t;
		}
	}

	public static void randomGetHashMapBench(int N) {
		HashMap<String, Integer> a = new HashMap<String, Integer>();
		String []seq = new String[N];
		int sum = 0;
		long start = 0;
		long duration = 0;
		Random g = new Random();

		for (int i = 0; i < N; i++) {
			String key = String.format("%09d", i);
			a.put(key, new Integer(i));
			seq[i] = key;
		}

		shuffle(seq);

		start = System.nanoTime();
		for (int i = 0; i < N; i++) {
			sum += a.get(seq[i]).intValue();
		}
		duration = System.nanoTime() - start;
		System.out.println(String.format("HashMap Random Access. N = %d: %f us/op.",
					N, (double)duration/(double)(N * 1e3)));
	}
	public static void main(String args[]) {
		int nr_elems = 10;

		if (args.length > 0) {
			nr_elems = Integer.parseInt(args[0]);
		}
		randomGetHashMapBench(nr_elems);
	}
}

