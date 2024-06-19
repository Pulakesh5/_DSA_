class Solution {
  public:
    double maxVolume(double p, double a) {
        // volume = l*b*h
        // max volume when l = (p-sqrt(p*p-24*a))/12
        // max volume = l*(a/2-l*(p/4-l))
        setprecision(2);
        double h = (p-sqrt(p*p-24*a))/12;
        double l = (p/4-2*h);
        double max_volume = l*h*h;
        return max_volume;
    }
};
