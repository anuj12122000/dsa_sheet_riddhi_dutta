class Solution
{

private:
    void helper(int open, int close, string s, vector<string> &res)
    {

        if (open == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }

        if (open > 0)
        {
            helper(open - 1, close, s + '(', res);
        }

        if (close > open)
            helper(open, close - 1, s + ')', res);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        int open = n;
        int close = n;
        helper(open, close, "", res);
        return res;
    }
};