import java.util.LinkedList;

class DataSmooth1 {
	DataSmooth1() {
	}

	public LinkedList<Double> dataSmooth(LinkedList<Show> shows) {

		for (Show s : shows) {
			int currNumOfEps = 0;
			double totalTime = 0;

			for (Episode e : s.episodes) {
				totalTime = totalTime + e.runTime;
				currNumOfEps++;
			}

			double avgShow = totalTime / currNumOfEps;

			s.setAvgLength(avgShow);
		}

		LinkedList<Double> returner = new LinkedList<Double>();

		int currPos = 0;

		for (Show s : shows) {
			// -1 is because of 0-based indexing, size might be 4, but position is 3
			if (currPos == 0 || currPos == shows.size() - 1) {
				returner.add(s.avgLength);
				currPos++;
			} else {
				returner.add(((shows.get(currPos - 1)).avgLength + (shows.get(currPos)).avgLength
						+ (shows.get(currPos + 1)).avgLength) / 3);
				currPos++;
			}
		}

		return returner;
	}

}