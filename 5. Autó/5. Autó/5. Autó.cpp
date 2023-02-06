#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> lista(N, vector<int>(3));

    for (int i = 0; i < N; i++)
    {
        lista[i][0] = i;
        cin >> lista[i][1] >> lista[i][2];
    }

    cerr << "előtt:\n";
    for (auto& triplet : lista)
        cout << triplet[0] << ". " << triplet[1] << " - " << triplet[2] << endl;

    sort(
        lista.begin(),
        lista.end(),
        [](vector<int> tr1, vector<int> tr2) {return tr1[2] < tr2[2]; });

    cerr << "után:\n";
    for (auto& triplet : lista)
        cout << triplet[0] << ". " << triplet[1] << " - " << triplet[2] << endl;

    cerr << "választás:\n";
    vector <int> mo;
    mo.push_back(lista[0][2] - 1);
    for (int i = 1; i < N; i++)
    {
        if (lista[i][1] > mo[mo.size() - 1]) {
            mo.push_back(lista[i][2] - 1);
        }
    }
    cout << mo.size() << endl;
    for (auto& elem : mo)
    {
        cout << elem << " ";
    }
}