//RUNTIME 6ms 	| 14.14%
//MEMORY 6.1MB	| 47.47%
class Solution {
public:
    string maskPII(string s) 
    {
        if(isEmail(s))
            return maskEmail(s);
        return maskPhone(s);
    }
    
    string maskEmail(string s)
    {
        string lowerstr = toLower(s);
        string mask = "*****";
        
        int pos = s.find('@');
        
        return lowerstr[0] + mask + lowerstr.substr(pos-1);  
    }
    
    string maskPhone(string s)
    {
        string out = "";
        int counter = 0;
        int n = 0;
        
        for(int i = 0; i < s.size() ; ++i)
        {
            n = isNumber(s[s.size() - i - 1]);
            if(n != -1)   
            {
                if(counter == 4 || counter == 7 || counter == 10)
                    out = "-" + out;
                if(counter < 4)
                    out = (char)n + out;
                else
                    out = "*" + out;
                counter++;
            }
        }
        if(counter > 10)
            out = "+" + out;
        return out;
    }
    
    string toLower(string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }
        return s;
    }
    
    bool isEmail(string s)
    {
        int pos = s.find('@');
        if(pos > 0)
            return true;
        return false;
    }
    
    int isNumber(char c)
    {
        if((c >= 48) && (c <=57))
            return c;
        return -1;
    }
};