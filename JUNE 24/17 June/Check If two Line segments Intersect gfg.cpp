class Solution {
  public:
    float line(int p1[], int q1[], int p2[]){
        float m = ((float)q1[1] - p1[1]) / ((float)q1[0] - p1[0]);
        return (float)p2[1] - p1[1] - m * (p2[0] - p1[0]);
    }

    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        float val1 = line(p1, q1, p2);
        float val2 = line(p1, q1, q2);
        
        float val11 = line(p2, q2, p1);
        float val12 = line(p2, q2, q1);
        
        if(val1 * val2 <= 0 && val11 * val12 <= 0){
            return "true";
        }
        
        return "false";
    }
};
