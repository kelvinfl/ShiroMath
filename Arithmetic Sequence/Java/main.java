public class main {

    public static void print(Object data){
        System.out.println(data);
    }

    public static void main(String[] args) {
	    ArithmeticSequence map = new ArithmeticSequence(new int[]{
	    		6,9,12,15,18,21
        });
	    print("Difference : " + map.getDifference());
	    print("Next Term : " + map.getNextTerm());
	    print("Value From Index(n) : " + map.getValueFromIndex(10));
	    print("Index From Value(value) : " + map.getIndexFromValue(30));
	    print("Sum : " + map.getSum());
	    print("Sum in Range(start,end) : " + map.getSum(0,1));
    }
}
