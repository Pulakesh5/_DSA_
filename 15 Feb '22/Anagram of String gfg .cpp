// make two frequency array
// count the commons and remove them from the strings, remaining is ans
int remAnagram(string str1, string str2)
{
    vector<int> count1(26,0),count2(26,0);
    int l1=str1.length(),l2=str2.length();
    for(int i=0;i<l1;i++)
            count1[str1[i]-'a']++;
    
    for(int i=0;i<l2;i++)
            count2[str2[i]-'a']++;
    
    int common=0;
    for(int i=0;i<26;i++)
        common+=min(count1[i],count2[i]);
    int ans=0;
    ans+=(l1-common);
    ans+=(l2-common);
    return ans;
}
