#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int swap_count = 0;

    vector<int> position_map(arr.size());

    for(int i=0; i<arr.size(); i++) {
        position_map[arr[i] - 1] = i;
    }

    for(int i=0; i<arr.size()-1; i++) {
        if (arr[i] != i + 1) {
            swap(arr[i], arr[position_map[i]]);
            swap(position_map[arr[i]-1], position_map[arr[position_map[i]]-1]);
            swap_count += 1;
        }
    }

    return swap_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
