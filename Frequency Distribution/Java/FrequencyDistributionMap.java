import java.util.ArrayList;
import java.util.Arrays;
import java.util.IntSummaryStatistics;
import java.util.List;

public class FrequencyDistributionMap {

    private int[] data;
    private int size;
    private int min;
    private int max;
    private int range;
    private Long classAmount;
    private int classLength;

    private List<Integer> _intervalBottom = new ArrayList<>();
    private List<Integer> _intervalTop = new ArrayList<>();
    private List<Integer> frequency = new ArrayList<>();
    private List<Double> classMark = new ArrayList<>();
    private List<Double> trueLowerLimit = new ArrayList<>();
    private List<Double> trueUpperLimit = new ArrayList<>();
    private List<Integer> cumulativeFrequencyLessThanType = new ArrayList<>();
    private List<Integer> cumulativeFrequencyGreaterThanType = new ArrayList<>();

    public FrequencyDistributionMap(int[] data){
        this.data = data;
        size = data.length;
        IntSummaryStatistics stat = Arrays.stream(data).summaryStatistics();
        min = stat.getMin();
        max = stat.getMax();
        range = max - min;
        classAmount = Math.round(1+((3.3)*Math.log10(data.length)));
        classLength = range / Math.round(classAmount);
        setupInterval();
        setupFrequency();
        setupLessAndGreater();
    }

    public String getInterval(int index, String splitter){
        return _intervalBottom.get(index) + splitter + _intervalTop.get(index);
    }

    public int getIntervalBottom(int index){
        return _intervalBottom.get(index);
    }

    public int getIntervalTop(int index){
        return _intervalTop.get(index);
    }

    public int getFrequency(int index){
        return frequency.get(index);
    }

    public double getClassMark(int index){
        return classMark.get(index);
    }

    public String getClassBoundaries(int index, String splitter){
        return trueLowerLimit.get(index) + splitter + trueUpperLimit.get(index);
    }

    public double getTrueLowerLimit(int index){
        return trueLowerLimit.get(index);
    }

    public double getTrueUpperLimit(int index){
        return trueUpperLimit.get(index);
    }

    public int getCumulativeFrequencyLessThanType(int index){
        return cumulativeFrequencyLessThanType.get(index);
    }

    public int getCumulativeFrequencyGreaterThanType(int index){
        return cumulativeFrequencyGreaterThanType.get(index);
    }

    public int getRow(){
        return _intervalBottom.size();
    }

    public int getSize(){
        return size;
    }

    public int getMin(){
        return min;
    }

    public int getMax(){
        return max;
    }

    public Double getMean(){
        Double total = 0.0;
        for (int i = 0; i < classAmount; i++){
            total = total + (frequency.get(i) * classMark.get(i));
        }
        return total / getSize();
    }

    public int getRange(){
        return range;
    }

    public Long getClassAmount(){ return classAmount; }

    public int getClassLength(){ return classLength; }

    private void setupInterval(){
        for (int i = 0; i < classAmount; i++){
            addInterval((int) (getMin() + ((getClassLength() + 1)*i)), (int) ((getMin() + getClassLength()) + ((getClassLength() + 1)*i)));
        }
    }

    private void setupFrequency(){
        for (int i = 0; i < getSize(); i++){
            for (int j = 0; j < classAmount; j++){
                if (data[i] >= _intervalBottom.get(j) && data[i] <= _intervalTop.get(j)){
                    int count = frequency.get(j);
                    count++;
                    frequency.set(j,count);
                }
            }
        }
    }

    private void setupLessAndGreater(){
        int countLess = 0;
        int countGreater = getSize();
        for (int i = 0; i < classAmount; i++){
            countLess += frequency.get(i);
            cumulativeFrequencyLessThanType.add(countLess);
            countGreater -= frequency.get(i);
            cumulativeFrequencyGreaterThanType.add(countGreater);
        }
    }

    private void addInterval(int intervalBottom, int intervalTop){
        _intervalBottom.add(intervalBottom);
        _intervalTop.add(intervalTop);
        frequency.add(0);
        classMark.add((double) intervalBottom + (((double) intervalTop - (double) intervalBottom) / 2));
        trueLowerLimit.add((double) intervalBottom - 0.5);
        trueUpperLimit.add((double) intervalTop + 0.5);
    }

}
