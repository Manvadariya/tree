using namespace std;
int main() {
    int n;
    cin >> n;
    int* eq1 = new int[n+1]; 
    int* eq2 = new int[n+1];

    for(int i = 0; i <= n; i++)
        cin >> eq1[i];
    for(int i = 0; i <= n; i++)
        cin >> eq2[i];
    for(int i = 0; i <= n; i++)
        cout << (eq1[i] + eq2[i]) << " ";
    return 0;
}