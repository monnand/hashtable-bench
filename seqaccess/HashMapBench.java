import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;

public class HashMapBench {
	public static void seqGetHashMapBench(int N) {
		HashMap<String, Integer> a = new HashMap<String, Integer>();
		int sum = 0;
		long start = 0;
		long duration = 0;

		for (int i = 0; i < N; i++) {
			String key = String.format("%09d", i);
			a.put(key, new Integer(i));
		}

		Iterator it = a.entrySet().iterator();
		start = System.nanoTime();
		while (it.hasNext()) {
			Map.Entry pair = (Map.Entry)it.next();
			sum += a.get(pair.getKey()).intValue();
		}
		duration = System.nanoTime() - start;
		System.out.println(String.format("HashMap Seq. Access. N = %d: %f us/op.",
					N, (double)duration/(double)(N * 1e3)));
	}
	public static void main(String args[]) {
		int nr_elems = 10;

		if (args.length > 0) {
			nr_elems = Integer.parseInt(args[0]);
		}
		seqGetHashMapBench(nr_elems);
	}
}

