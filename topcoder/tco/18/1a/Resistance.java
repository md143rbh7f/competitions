import java.math.*;
import java.util.*;

public class Resistance {
public double[] spyProbability(int n, int s, String[] missions) {
	ArrayList<Integer> fails = new ArrayList<>();
	for (String mission : missions) {
		if (mission.charAt(0) == 'F') {
			fails.add(Integer.parseInt(mission.substring(1).toString(), 2));
		}
	}

	int ok = 0;
	double[] probs = new double[n];
	outer: for (int m = 0; m < 1<<n; m++) {
		if (Integer.bitCount(m) == s) {
			for (Integer f : fails) {
				if ((m & f) == 0) {
					continue outer;
				}
			}
			ok++;
			for (int i = 0; i < n; i++) {
				probs[n - i - 1] += (m >> i) & 1;
			}
		}
	}

	if (ok == 0) {
		return new double[]{};
	}
	for (int i = 0; i < n; i++) {
		probs[i] /= ok;
	}
	return probs;
}
}
