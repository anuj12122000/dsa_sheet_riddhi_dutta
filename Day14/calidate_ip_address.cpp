class Solution
{
private:
    bool checkip4(string s)
    {

        int cdot = 0;
        int x = 0;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {

            if (s[i] == '.')
            {
                cdot++;
                continue;
            }
            else
            {
                string temp = "";

                while (i < n && s[i] != '.')
                {

                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        temp += s[i];
                        i++;
                    }
                    else
                    {
                        return false;
                    }
                }

                if (temp.size() > 3)
                {
                    return false;
                }

                x++;

                if (temp.size() > 1)
                {
                    if (temp[0] == '0')
                    {
                        return false;
                    }
                }

                int a = stoi(temp);
                if (a > 255 || a < 0)
                {
                    return false;
                }

                i--;
            }
        }

        if (cdot != 3 || x != 4)
        {
            return false;
        }

        return true;
    }

    bool check(string s)
    {
        int cdot = 0;
        int n = s.size();
        int x = 0;
        for (int i = 0; i < n; i++)
        {

            if (s[i] == ':')
            {
                cdot++;
                continue;
            }
            else
            {
                x++;
                string temp = "";
                while (i < n && s[i] != ':')
                {
                    if ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= '0' && s[i] <= '9'))
                    {
                        temp += s[i];
                    }
                    else
                    {
                        return false;
                    }

                    if (temp.size() > 4)
                    {
                        return false;
                    }

                    i++;
                }

                i--;
            }
        }
        if (cdot != 7 || x != 8)
        {
            return false;
        }
        return true;
    }

public:
    string validIPAddress(string queryIP)
    {
        if (checkip4(queryIP))
        {
            return "IPv4";
        }
        else if (check(queryIP))
        {
            return "IPv6";
        }
        return "Neither";
    }
};