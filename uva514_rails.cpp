#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    vector<vector<vector<long unsigned int> > > input;
    while (cin >> n && n != 0)
    {
        vector<vector<long unsigned int> > input_n;
        while (true)
        {
            vector<long unsigned int> line(n);
            cin >> line[0];
            if (line[0] == 0)
                break;
            for (int j = 1; j < n;)
                cin >> line[j++];
            input_n.push_back(line);
        }
        input.push_back(input_n);
    }
    for (vector<vector<long unsigned int> > vct_n: input)
    {
        for (vector<long unsigned int> each :vct_n)
        {
            stack<long unsigned int> st;
            bool possible = true;
            long unsigned int k = 1;
            for (long unsigned int m = 0; m < each.size(); m++)
            {
                while (k <= each.size() && (st.empty() || st.top() != each[m]))
                    st.push(k++);
                if (!st.empty() && st.top() == each[m])
                    st.pop();
                else {
                    possible = false;
                    break;
                }
            }
            cout << (possible ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}