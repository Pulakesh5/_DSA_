int minSteps(string str) {
    // Write your code here.
    char prev=str[0];
    int len = str.size();
    int counta=0, countb=0;
    for(int i=1;i<len;i++)
    {
        if(str[i]!=prev)
        {
            if(prev=='a') counta++;
            if(prev=='b') countb++;
            prev=str[i];
        }
    }
    if(prev=='a') counta++;
    if(prev=='b') countb++;
    return min(counta,countb)+1;
}
