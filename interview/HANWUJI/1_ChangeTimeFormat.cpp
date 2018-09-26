#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void getData(const string& time12, int* time, string& flag)
{
	int id = 0;
	int start = 0;
	while (time12[id] != ':')
		++id;
	time[0] = stoi(time12.substr(start, id - start));
	start = ++id;
	while (time12[id] != ':')
		++id;
	time[1] = stoi(time12.substr(start, id - start));
	++id;
	time[2] = stoi(time12.substr(id, time12.size() - id - 2));
	flag = time12.substr(id + 2, time12.size() - id);
}

int main()
{
    freopen("1.txt", "r", stdin);
    string time12;
    cin >> time12;

    int time[3];
    string flag;

    getData(time12, time, flag);

    // for(int i = 0; i < 3; ++i)
    // 	cout << time[i] << endl;
    // cout << flag << endl;

    if (flag == "PM")
    {
    	if (time[0] != 12)
    		printf("%02d:%02d:%02d\n", time[0] + 12, time[1], time[2]);
    	else
    		printf("%02d:%02d:%02d\n", time[0], time[1], time[2]);
    }

    if (flag == "AM")
    {
    	if (time[0] == 12)
    		printf("%02d:%02d:%02d\n", time[0] - 12, time[1], time[2]);
    	else
    		printf("%02d:%02d:%02d\n", time[0], time[1], time[2]);
    }

    fclose(stdin);
    return 0;
}