int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    int *_xor= (int*) malloc(n*sizeof(int));
    for(int i=0;i<(n-1);i++)
    {
        _xor[i]=(arr[i])^(arr[i+1]);
    }
    _xor[n-1]=arr[n-1];
    return _xor;
    
}
