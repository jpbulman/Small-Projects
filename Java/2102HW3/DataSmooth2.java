import java.util.LinkedList;

class DataSmooth2 {
	DataSmooth2() {
	}

	// returns the "smoothed" runtime of a list of shows, basically each non-end
	// data point for
	// runtime is replaced with the average of adjacent data
	public LinkedList<Double> dataSmooth(LinkedList<Show> shows) {
		LinkedList<Double> smoothed = new LinkedList<Double>();
		LinkedList<Double> averages = new LinkedList<Double>();
		for (Show s : shows) {
			averages.add(findAverage(s));
		}
		smoothed.add(averages.getFirst());
		for (int i = 1; i < averages.size() - 1; i++) {
			smoothed.add((averages.get(i - 1) + averages.get(i) + averages.get(i + 1)) / 3);
		}
		if (shows.size() > 1) {
			smoothed.add(averages.getLast());
		}
		return smoothed;
	}

	// finds the average run time of a show based on its list of episodes
	public double findAverage(Show some) {
		double average = 0;
		int counter = 0;
		for (Episode e : some.episodes) {
			counter++;
			average = average + e.runTime;
		}
		average = average / counter;
		return average;
	}
}