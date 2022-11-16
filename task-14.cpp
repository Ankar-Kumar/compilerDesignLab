
//kamol code 

#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> production;
map<char, set<char>> first, follow;
void takeInput()
{
    production['E'].push_back("TR");
    production['R'].push_back("+TR");
    production['R'].push_back("#");
    production['T'].push_back("FY");
    production['Y'].push_back("*FY");
    production['Y'].push_back("#");
    production['F'].push_back("(E)");
    production['F'].push_back("i");

    // for (auto it : production)
    // {
    //     cout << it.first << ": ";
    //     for (auto iit : it.second)
    //     {
    //         cout << iit << " ";
    //     }
    //     cout << endl;
    // }
}
void takeFirst()
{
    first['E'].insert('i');
    first['E'].insert('(');
    first['R'].insert('+');
    first['R'].insert('#');
    first['T'].insert('i');
    first['T'].insert('(');
    first['Y'].insert('*');
    first['Y'].insert('#');
    first['F'].insert('i');
    first['F'].insert('(');

    // for (auto it : first)
    // {
    //     cout << it.first << ": ";
    //     for (auto iit : it.second)
    //     {
    //         cout << iit << " ";
    //     }
    //     cout << endl;
    // }
}

bool isCapital(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}
set<char> isVisited;
void findFollow(char ch)
{
    // find the follow for the character ch

    // if visited then return without doing nothing
    if (isVisited.count(ch)) // isVIsited e ch found hole return kore dibo
        return;
    isVisited.insert(ch);
    // check every production right side
    for (auto it : production)
    {
        for (auto prod : it.second)//right side string 
        {
            bool isFound = false;
            // use isFound to check if ch is found of not
            for (auto x : prod)//char goes to x
            {

                if (isFound) // jodi ch pai tahole next char check krbo
                {
                    // if we fond ch in the last position
                    if (isCapital(x))
                    {
                        // if it is non-terminal push the first of the non terminal into the follow of ch
                        for (auto ft : first[x])
                        {
                            follow[ch].insert(ft);
                        }
                        // jodi esp pai othoba ch er soman hoy
                        // tahole dhore nibo eitao ch er soman
                        if (first[x].count('#') or x == ch)
                        {
                            isFound = true;
                        }
                        else
                            isFound = false;
                    }
                    else
                    {
                        follow[ch].insert(x);
                        isFound = false;
                    }
                }
                else
                {
                    if (x == ch)
                    {
                        isFound = true;
                    }
                }
            }
            // if we found ch at the last of the character
            if (isFound == true)
            { // the we find the follow of left side production and push it to follow of ch
                findFollow(it.first);

                for (int ft : follow[it.first])
                {
                    follow[ch].insert(ft);
                }
            }
        }
    }

    follow[ch].erase('#');
}

// first follow complete

// now we need to make the shit table
map<pair<char, char>, string> table;

void makeTable()
{

    for (auto it : production)//E->TR
    {
        for (auto prod : it.second)//TR
        {
            bool isBreak = false;
            //x means char of prod string 
            for (auto x : prod)//T,R
            {
                if (isCapital(x))
                { // capital hoile first er ghore production bosbe
                    for (auto ft : first[x])//
                    {
                        table[{it.first, ft}] = prod; 
                    }
                    // first er ghore jodi esp thake taile next  char e jabe
                    // na hoile break
                    // if (first[x].count('#'))
                    // {
                    //     continue;
                    // }
                    // else
                    // {
                    //     isBreak = true;
                    //     break;
                    // }

                    // sortcut
                    isBreak = true;
                    break;
                }
                else
                {
                    // non terminal jodi esp hoy taile follow te maro
                    if (x == '#')
                    {
                        // for (auto ft : follow[it.first])
                        // {
                        //     table[{it.first, ft}] = prod;
                        // }
                        // isBreak = true;
                        // break;

                        // shortcut
                    }
                    else
                    { // na hoile oi char e mere break maro
                        table[{it.first, x}] = prod;//oi terminal ghore production bosbe...
                        isBreak = true;
                        break;
                    }
                }
            }
            // sob esp hoile follow te maro
            if (isBreak == false)//jodi E-># hoi tahole
            {
                for (auto ft : follow[it.first])//E er follow ghor gula table a dibo
                {
                    table[{it.first, ft}] = prod; // ekhane ft holo E er sokol follow 
                }
            }
        }
        table.erase({it.first, '#'});
    }
}
int main()
{
    takeInput();
    takeFirst();
    follow['E'].insert('$');
    for (auto it : production)
    {
        findFollow(it.first);//E pass krchi follow function e
        // cout << it.first << " : ";

        // for (auto ch : follow[it.first])
        // {
        //     cout << ch << " ";
        // }
        // cout << endl;
    }
    makeTable();

    for (auto it : table)
    {
        cout << "[ " << it.first.first << " , " << it.first.second << " ] : " << it.second << endl;
    }
}