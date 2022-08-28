class Solution {
public:
    map<string, string> code2url;
    map<string, string> url2code;
    string alphabet= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        srand((unsigned) time(NULL)); 
        string code="";
        while(url2code.find(longUrl)==url2code.end()){
            code="";
            for(int i=0;i<6;i++){
                int my_rand = (rand())%62;
                code+=alphabet[my_rand];
            }
            if(code2url.find(code)==code2url.end())
            {
                cout<<code<<endl;
                url2code[longUrl]=code;
                code2url[code]=longUrl;
                return code;
            }
            continue;
        }
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code2url[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
