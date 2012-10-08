/*
ID:dingyag1
LANG:C++
TASK:numtri
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[1001][1001];

int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
}


	

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}