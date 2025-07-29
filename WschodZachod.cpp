#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, w, z;

void bfs(vector<int> tablicaPolaczen[], int wejscie, int numerpociagu, int ilosc, int **tablicaOdleglosci)
{
    //int dodatnik = 0;
    int tablicaOdleglosciTemp[n];
    for (int i = 0; i < n; i++)
    {
        tablicaOdleglosciTemp[i] = -1;
    }
    tablicaOdleglosciTemp[wejscie] = 0;
    queue<int> kolejka;
    kolejka.push(wejscie);

    while (!kolejka.empty())
    {
        int obecny = kolejka.front();

        kolejka.pop();
        for (int i = 0; i < tablicaPolaczen[obecny].size(); i++)
        {
            int sasiad = tablicaPolaczen[obecny][i];
            if (tablicaOdleglosciTemp[sasiad] == -1)
            {

                /*if (numerpociagu >= 1)
                {
                    if (tablicaOdleglosciTemp[sasiad] == tablicaOdleglosci[numerpociagu - 1][sasiad])
                    {
                        dodatnik++;
                    }
                }*/
                tablicaOdleglosciTemp[sasiad] = tablicaOdleglosciTemp[obecny] + 1 /*+ dodatnik*/;
                kolejka.push(sasiad);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        tablicaOdleglosci[numerpociagu][i] = tablicaOdleglosciTemp[i];
    }

    cout << tablicaOdleglosciTemp[0];
    cout << "a";
}

int main()
{
    cin >> n >> w >> z;
    vector<int> tablicaPolaczen[n];
    for (int i = 0; i < n - 1; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        temp1--;
        temp2--;
        tablicaPolaczen[temp1].push_back(temp2);
        tablicaPolaczen[temp2].push_back(temp1);
    }
    int ilosc;
    cin >> ilosc;
    int **tablicaOdleglosci = new int *[ilosc];
    for (int i = 0; i < ilosc; i++)
    {
        tablicaOdleglosci[i] = new int[n];
    }
    int tablicaOdleglosciTempMain[ilosc][n];

    int tablicaWejscia[ilosc];      // ilosc
    for (int i = 0; i < ilosc; i++) // ilosc
    {
        cin >> tablicaWejscia[i];
        tablicaWejscia[i]--;
    }

    bool tablicaZachod[n];
    for (int i = 0; i < n; i++)
    {
        tablicaZachod[i] = false;
        if (tablicaPolaczen[i].size() == 1)
        {
            tablicaZachod[i] = true;
        }
    }
    for (int i = 0; i < ilosc; i++) // ilosc
    {
        tablicaZachod[tablicaWejscia[i]] = false;
    }

    for (int i = 0; i < ilosc; i++)
    {
        bfs(tablicaPolaczen, tablicaWejscia[i], i, ilosc, tablicaOdleglosci);
    }

    for (int i = 0; i < ilosc; ++i)
    {
        memcpy(tablicaOdleglosciTempMain[i], tablicaOdleglosci[i], ilosc * n * sizeof(int));
    }
    cout << endl << "TablicaOdleglosci:" << endl;
    for (int i = 0; i < ilosc; i++)
    {
        cout << "Pociag " << i << " -  ";
        for (int j = 0; j < n; j++)
        {
            cout << tablicaOdleglosci[i][j] << " ";
        }
        cout << endl;
    }
    

    for (int i = 0; i < ilosc; ++i)
    {
        delete[] tablicaOdleglosci[i];
    }
    delete[] tablicaOdleglosci;
}