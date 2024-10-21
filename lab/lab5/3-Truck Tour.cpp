
using namespace std;
struct PetrolPump{
    int petrol;
    int distance;
};

int calculateIndex(queue<PetrolPump>& q){
    int start = 0, defict = 0, surplus = 0;
    int n = q.size();
    for(int i = 0; i < n; i++){
        PetrolPump current = q.front();
        q.pop();
        surplus += current.petrol - current.distance;
        if(surplus < 0){
            start = i + 1;
            defict = surplus;
            surplus = 0;
        }
    }
    return (surplus + defict >= 0) ? start : -1;
}

int main(){
    int n;
    cin >> n;
    queue<PetrolPump> q;
    for(int i = 0; i<n; i++){
        PetrolPump p;
        cin >> p.petrol>>p.distance;
        q.push(p);
    }
    cout << calculateIndex(q);
    return 0;
}