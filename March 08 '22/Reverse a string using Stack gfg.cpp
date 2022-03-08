char* reverse(char *S, int len)
{
    char* retn = new char[len+1];
    stack<char> s;
    int i=0;
    for(;i<len;){
        s.push(S[i]);
        i++;
    }
    i=0;
    while(!s.empty()){
        retn[i]=s.top();
        s.pop();
        i++;
    }
    retn[len]=NULL;
    return retn;
}
