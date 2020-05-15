#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
int n = 10;
string str = "";
int shoroo = 1;

using namespace std;
int minPath = 99999;
string pathstr = "";
string bestpath = "";

/// voroodi ha

int completed[100000], cost = 0;
int costeveryitrate = 0;
string costlog = "";

int ary[5][5];
int ary2[5][5];
int test[10][10] =
    {
        {999, 10, 5, 999, 4, 999, 3, 999, 8, 999},
        {10, 999, 999, 5, 999, 8, 999, 9, 999, 4},
        {5, 999, 999, 10, 5, 999, 4, 999, 9, 999},
        {999, 5, 10, 999, 999, 9, 999, 8, 999, 5},
        {4, 999, 5, 999, 999, 3, 5, 999, 999, 999},
        {999, 8, 999, 9, 3, 999, 999, 5, 4, 999},
        {3, 999, 4, 999, 5, 999, 999, 3, 999, 999},
        {999, 9, 999, 8, 999, 5, 3, 999, 5, 999},
        {8, 999, 9, 999, 999, 4, 999, 5, 999, 3},
        {999, 4, 999, 5, 999, 999, 999, 999, 3, 999}

};

void decresedimention()
{
    printf("\n\nThe Main cost list is:");

    for (int i = 0; i < n; i++)
    {
        printf("\n");

        for (int j = 0; j < n; j++)
            printf("\t%d", test[i][j]);
    }

    for (int i = 0; i < n; i += 2)
    {
        printf("\n");

        for (int j = 0; j < n; j += 2)
            if (i == j)
            {
                ary2[i / 2][j / 2] = test[i][j + 1];
                ary[i / 2][j / 2] = 999;
            }
            else
            {

                ary[i / 2][j / 2] = test[i][j];
                ary2[i / 2][j / 2] = test[i][j];
            }
    }

    printf("\n\nThe standard Tso cost:");

    for (int i = 0; i < n / 2; i++)
    {
        printf("\n");

        for (int j = 0; j < n / 2; j++)
            printf("\t%d", ary[i][j]);
    }

    printf("\n\nOur Tso cost:");

    for (int i = 0; i < n / 2; i++)
    {
        printf("\n");

        for (int j = 0; j < n / 2; j++)
            printf("\t%d", ary2[i][j]);
    }
}

void permute(string a, int l, int r)
{
    if (l == r)
    {
        costeveryitrate = 0;
        for (int h = 0; h < a.size(); h++)
        {

            int b = a[h] * 1 - 49;
            int c = a[h + 1] * 1 - 49;
            costeveryitrate += ary2[b][c];

            // printf("%d\t", costeveryitrate);
        }
        if (minPath > costeveryitrate)
        {
            minPath = costeveryitrate;
            pathstr = a;
            bestpath = a;
        }
        if (minPath == costeveryitrate)
        {

            pathstr = pathstr + "," + a;
        }

        // cout << a << endl;
    }

    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    decresedimention();

    int dimention = n / 2;
    string strbadd = "";

    for (int s = 0; s < dimention; s++)
    {
        if (s + 1 != shoroo)
        {
            str = str + std::to_string(s + 1);
        }
    }
    strbadd = std::to_string(shoroo) + str;
    cout << "\n citys :" + strbadd << endl;

    int m = str.size();
    permute(str, 0, m - 1);

    cout << "----------------" << endl;
    cout << pathstr << endl;
    bestpath = std::to_string(shoroo) + bestpath;
    cout << bestpath << endl;
    int initial = 1;
    string pathstringmain = "";
    int maincost = 0;
    for (int u = 0; u < bestpath.size(); u++)
    {
        int b = bestpath[u] * 1 - 49;
        int c = bestpath[u + 1] * 1 - 49;
        if (initial == 1)
        {
            pathstringmain += bestpath[u];
            pathstringmain += "A--";
            int costmohasebe = ary2[b][b];
            pathstringmain += std::to_string(costmohasebe);
            pathstringmain += "--";
            maincost = maincost + costmohasebe;
            pathstringmain += std::to_string(maincost);
            pathstringmain += "-->";
            pathstringmain += bestpath[u];
            pathstringmain += "B\t";
            initial = 2;

            pathstringmain += bestpath[u];
            pathstringmain += "B--";
            costmohasebe = ary2[b][c];
            pathstringmain += std::to_string(costmohasebe);
            pathstringmain += "--";
            maincost = maincost + costmohasebe;
            pathstringmain += std::to_string(maincost);
            pathstringmain += "-->";
            pathstringmain += bestpath[u + 1];
            pathstringmain += "B\t";
        }
        else
        {
            pathstringmain += bestpath[u];
            pathstringmain += "B--";
            int costmohasebe = ary2[b][b];
            pathstringmain += std::to_string(costmohasebe);
            pathstringmain += "--";
            maincost = maincost + costmohasebe;
            pathstringmain += std::to_string(maincost);
            pathstringmain += "-->";
            pathstringmain += bestpath[u];
            pathstringmain += "A\t";
            initial = 1;

            pathstringmain += bestpath[u];
            pathstringmain += "A--";
            costmohasebe = ary2[b][c];
            pathstringmain += std::to_string(costmohasebe);
            pathstringmain += "--";
            maincost = maincost + costmohasebe;
            pathstringmain += std::to_string(maincost);
            pathstringmain += "-->";
            pathstringmain += bestpath[u + 1];
            pathstringmain += "A\t";
        }
    }
    cout << pathstringmain << endl;

    cout << maincost << endl;

    return 0;
}
