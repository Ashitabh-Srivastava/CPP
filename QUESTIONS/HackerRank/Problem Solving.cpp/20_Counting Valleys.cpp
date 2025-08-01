#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path)
{
    int nvaly = 0;

    int level = 0;
    int valley = 0;
    for (int i = 0; i < steps; i++)
    {
        if (path[i] == 'U')
        {
            level++;
        }
        else if (path[i] == 'D')
        {
            level--;

            if (level < 0)
            {
                valley--;
            }
        }

        if (level == 0 && valley < 0)
        {
            nvaly++;
            valley = 0;
        }
    }

    return nvaly;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
