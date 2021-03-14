#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

int main()
{
    int N_k; cin >> N_k; // кол-во навыков
    vector<int> N(N_k), P(N_k);
    for (int i = 0; i < N_k; i++)
        cin >> N[i];
    for (int i = 0; i < N_k; i++)
        cin >> P[i];
    int C_k; cin >> C_k; // кол-во кандидатов
    vector<int> List; // итоговый список отобранных специалистов
    for (int i = 0; i < C_k; i++)
    {
        int max_i = -1, S_k; 
        cin >> S_k;
        if (S_k == 0) continue;
        for (int j = 0; j < S_k; j++) // перебираем навыки кандидата, ищем самый затратный
        {
            int S;
            cin >> S; S--; // отнимаем 1, т.к. индексация векторов N и P начинается с 0.
            if (max_i == -1 || P[S] > P[max_i])
                max_i = S;
        }
        if (N[max_i] > 0)
        {
            List.push_back(i + 1); // записываем в список номер прошедшего отбор кандидата
            N[max_i]--;
        }
    }
    for (int i = 0; i < List.size(); i++) // выводим итоговый список с номерами отобранных специалистов
        cout << List[i] << ' ';
    return 0;
}
