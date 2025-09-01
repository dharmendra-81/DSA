```cpp
int hash[26] = {0};
    string str = "geeksforgeeks";
    for (int i = 0; i < str.length(); i++) {
        hash[str[i] - 'a']++;
    }
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--) {
        char ch;
        cout << "Enter the character to check: ";
        cin >> ch;
        cout << "The character " << ch << " appears " << hash[ch -       'a'] << " times." << endl;
    }
```
