/*

*/

//version 1 ()
class Solution {
    
    private double radius;
    
    private double xx, yy;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        xx = x_center;
        yy = y_center;
    }
    
    public double[] randPoint() {
        double len = Math.sqrt(Math.random()) * radius;
        double degree = Math.random() * 2 * Math.PI;
        double x = xx + len * Math.cos(degree);
        double y = yy + len * Math.sin(degree);
        return new double[] {x, y};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */