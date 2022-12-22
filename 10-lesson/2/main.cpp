#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

map<string, string> f;
map<char, vector<string>> firstChar;
set<string> st;

int main()
{
    ifstream fin;
    fin.open("dictionary.txt");

    if (!fin.is_open())
    {
        cout << "err\n";
        return EXIT_SUCCESS;
    }
    do
    {
        string a;
        string b;
        fin >> a >> b;
        firstChar[a[0]].push_back(a);
        f[a] = b;
        st.insert(a);
    }while(fin);

    bool flag = true;
    while (flag)
    {
        cout << "1 -- list the words by the first char\n";
        cout << "2 -- search by word\n";
        cout << "3 -- translate your word\n";

        int choice = 0;
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "enter char your char: ";
                char c;
                cin >> c;
                for (auto s: firstChar[c])
                {
                    cout << s << '\n';
                }
            }
                break;

            case 2:
            {
                cout << "enter your word: ";
                string t;
                cin >> t;
                if (st.find(t) != st.end())
                {
                    cout << "yes, there is your word in a dictionary\n";
                } else
                {
                    cout << "there is no such word\n";
                }
            }
                break;

            case 3:
            {
                cout << "enter your word: ";
                string t;
                cin >> t;
                cout << f[t] << '\n';
            }
                break;

            default:
                cout << "you need to enter the number from 1 to 3\n";
                break;
        }

        cout << "do you want to continue?: (y/n)";
        char tmp;
        cin >> tmp;
        if (tmp != 'y')
        {
            flag = false;
        }
    }
}
