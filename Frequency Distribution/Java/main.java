public class Main {

    public static void print(Object data){
        System.out.println(data);
    }

    public static void main(String[] args) {

        FrequencyDistributionMap map = new FrequencyDistributionMap(new int[]{
                27,47,54,64,75,
                35,47,56,64,75,
                38,48,58,64,77,
                39,48,58,65,79,
                40,49,59,65,81,
                42,50,60,66,84,
                42,50,60,69,85,
                43,52,62,69,89,
                45,53,62,72,92,
                46,53,63,73,94
        });

        print("Count : " + map.getSize());
        print("Min   : " + map.getMin());
        print("Max   : " + map.getMax());
        print("Range : " + map.getRange());
        print("Class Amount  : " + map.getClassAmount());
        print("Class Length : " + map.getClassLength());

        for (int i = 0; i < map.getRow(); i++){
            print( " | " +
                    map.getInterval(i, "-") + " | " +
                    map.getFrequency(i) + " | " +
                    map.getClassMark(i) + " | " +
                    map.getClassBoundaries(i, "-") + " | " +
                    map.getCumulativeFrequencyLessThanType(i) + " | " +
                    map.getCumulativeFrequencyGreaterThanType(i) + " | "
            );
        }

        print("Mean : " + map.getMean());

    }
}
