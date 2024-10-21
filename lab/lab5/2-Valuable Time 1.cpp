using namespace std;

int calculateTime(deque<int>& ravi, const vector<int>& salma){
    int time = 0;
    for(int s: salma){
        while (ravi.front() != s)
        {
            ravi.push_back(ravi.front());
            ravi.pop_front();
            time++;
        }
        ravi.pop_front();
        time++;        
    }
    return time;
}

int main(){
    int N;
    cin >> N;
    if(N==0){cout << -1; exit(0);}
    deque<int> ravi(N);
    vector<int> salma(N);
    for(int i = 0; i<N;i++){
        cin >> ravi[i];
    }
    for(int i = 0; i<N;i++){
        cin >> salma[i];
    }
    cout << calculateTime(ravi, salma);
}