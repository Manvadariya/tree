    
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    char* str = new char[n];
    for (int i = 0; i < n; ++i) {
        str[i] = cin.get(); 
    }

    int freq[26] = {0};
    for (int i = 0; i < n; ++i) { 
        if (isalpha(str[i])) {
            char c = tolower(str[i]);
            freq[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        cout << freq[i] << " ";
    }
    cout << endl; 

    delete[] str; 
    return 0;
}

