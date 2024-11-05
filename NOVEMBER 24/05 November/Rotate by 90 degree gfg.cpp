void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int N = mat.size();
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int c=0; c<(N/2); c++)
    {
        for(int i=0; i<N; i++)
            swap(mat[i][c], mat[i][N-1-c]);
    }
}
