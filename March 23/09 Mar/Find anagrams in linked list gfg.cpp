vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<int> s_count(26,0), str_count(26,0);
        int s_length=s.size(),i=0;
        vector<Node*> anagrams;
        
        for(char ch:s)
            s_count[ch-'a']++;
        
        Node *start=head, *end=head, *anagram_node, *prev;
        
        while(i<s_length && end)
        {
            str_count[end->data-'a']++;
            end=end->next;
            i++;
        }
        
        while(end)
        {
            if(str_count==s_count)
            {
                anagram_node=start;
                
                prev=start;
                start=start->next;
                
                while(start!=end)
                {
                    prev=start;
                    start=start->next;
                }
                prev->next=NULL;
                anagrams.push_back(anagram_node);
                
                for(int i=0;i<26;i++)
                    str_count[i]=0;
                i=0;
                while(i<s_length && end)
                {
                    str_count[end->data-'a']++;
                    end=end->next;
                    i++;
                }
            }
            else
            {
                str_count[start->data-'a']--;
                str_count[end->data-'a']++;
                start=start->next;
                end=end->next;
            }
        }
        
        if(str_count==s_count)
        {
            anagram_node=start;
                
            prev=start;
            start=start->next;
            
            while(start!=end)
            {
                prev=start;
                start=start->next;
            }
            prev->next=NULL;
            anagrams.push_back(anagram_node);
        }
        
        return anagrams;
        
    }
