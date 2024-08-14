package problem3;

import java.text.NumberFormat;
import java.util.SplittableRandom;

public class DrawRandomNumber {
    private static final SplittableRandom random = new SplittableRandom();

    public static int drawRandomNumber() {
        int draw = random.nextInt(1, 101);
        if (draw <= 20) {
            return 1;
        } else if (draw <= 50) {
            return 2;
        }
        return 3;
    }

    private static void displayProbabilities(int[] counts, int totalIterations) {
        NumberFormat percentFormat = NumberFormat.getPercentInstance();
        percentFormat.setMaximumFractionDigits(2);

        for (int i = 0; i < counts.length; i++) {
            double probability = (double) counts[i] / totalIterations;
            System.out.println((i + 1) + ": " + percentFormat.format(probability));
        }
    }

    public static void main(String[] args) {
        int[] countsFor10000Iterations = new int[3];
        int[] countsForAnother10000Iterations = new int[3];
        int totalIterations = 10_000;

        for (int i = 0; i < totalIterations; i++) {
            int draw = drawRandomNumber();
            countsFor10000Iterations[draw - 1]++;
        }
        displayProbabilities(countsFor10000Iterations, totalIterations);

        for (int i = 0; i < totalIterations; i++) {
            int draw = drawRandomNumber();
            countsForAnother10000Iterations[draw - 1]++;
        }
        displayProbabilities(countsForAnother10000Iterations, totalIterations);
    }
}
