public class ArithmeticSequence {

    int[] idata = null;
    double[] ddata = null;

    public ArithmeticSequence(int[] idata){
        this.idata = idata;
    }

    public ArithmeticSequence(double[] ddata){
        this.ddata = ddata;
    }

    public Object getDifference(){
        Object r = "";
        if (idata == null){
            r = ddata[1]-ddata[0];
        } else {
            r = idata[1]-idata[0];
        }
        return r;
    }

    public Object getNextTerm(){
        Object r = "";
        if (idata == null){
            r = ddata[ddata.length - 1] + (double) getDifference();
        } else {
            r = idata[idata.length - 1] + (int) getDifference();
        }
        return r;
    }

    // public String getNthTerm(){return "";}

    public Object getValueFromIndex(int n){
        Object r = "";
        if (idata == null){
            r = ddata[0] + ((double) getDifference() * (n-1));
        } else {
            r = idata[0] + ((int) getDifference() * (n-1));
        }
        return r;
    }

    public Object getIndexFromValue(Object value){
        Object r = "";
        if (idata == null){
            r = (((double) value - ddata[0]) / (double) getDifference()) + 1;
        } else {
            r = (((int) value - idata[0]) / (int) getDifference()) + 1;
        }
        return r;
    }

    public Object getSum(){
        Object r = "";
        if (idata == null){
            Double i = ddata[0];
            for (int j = 1; j < ddata.length; j++){
                i += ddata[j];
            }
            r = i;
        } else {
            int i = idata[0];
            for (int j = 1; j < idata.length; j++){
                i += idata[j];
            }
            r = i;
        }
        return r;
    }

    public Object getSum(int start, int end){
        Object r = "";
        if (idata == null){
            Double i = 0.0;
            for (int j = start; j <= end; j++){
                i += ddata[j];
            }
            r = i;
        } else {
            int i = 0;
            for (int j = start; j <= end; j++){
                i += idata[j];
            }
            r = i;
        }
        return r;
    }

}
