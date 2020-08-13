class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int len = s.length(); int size = words.size();
        vector<int>result;
        if(size <= 0 || len <= 0)
            return result;
        int wordsize = words[0].length();
        if(size*wordsize > len)
            return result;
        unordered_map<string,int>word;
        for(int i=0 ; i < size ; i++)
        {
            word[words[i]]++;
        }
        
        for(int i = 0 ; i < len-(wordsize*size)+1 ; i++)
        {
            unordered_map<string , int>visit;
            int j = 0;
            for( ; j<size ; j++)
            {
                string w = s.substr(i+j*wordsize , wordsize);
                if(word.find(w) != word.end())
                {
                    visit[w]++;
                   if(visit[w] > word[w])
                       break;
                }   
                else
                    break;
            }
            if(j == size)
                result.push_back(i);
        }
        return result;
  }
};