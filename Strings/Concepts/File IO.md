#### Writing in a file
```cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    string s="This is text note";
    ofstream out("sample.txt");
    out<<s;
    return 0;
}
```

#### Reading a file
```cpp
string s;
ifstream in("sample.txt");
//Method 1
in>>s;
cout<<s; //This
// After next line or space the content will not be read.

//Method 2
getline(in,s);
cout<<s; //This is text note
```


