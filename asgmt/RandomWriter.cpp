#include <string>
#include <iostream>
#include <fstream>
#include "vector.h"
#include "map.h"
#include "simpio.h"
#include "random.h"

using namespace std;

void promptUserFile(ifstream &fileStrem, string prompt);
void writeRandom();
string analyseFile(ifstream &fileStream, int order, Map<Vector<char>> &seeds);
string initSeed(Map<int> &frequently);
void writeRandom(Map<Vector<char>> &seeds, string initSeed);

int main()
{
    ifstream fileStream;
    promptUserFile(fileStream, "Please enter filename: ");
    int order;
    cin >> order;
    Map<Vector<char>> seeds;
    string seed = analyseFile(fileStream, order, seeds);
    writeRandom(seeds, seed);
    return 0;
}

void promptUserFile(ifstream &fileStream, string prompt)
{
    while (true)
    {
        cout << prompt;
        string filename = GetLine();
        fileStream.open(filename.c_str());
        if (!fileStream.fail())
            break;
        cout << "Can't open file \"" << filename << "\"" << endl;
        fileStream.clear();
    }
}

string analyseFile(ifstream &fileStream, int order, Map<Vector<char>> &seeds)
{
    Map<int> frequently;

    string seed;
    string line;

    while (true)
    {
        int ch = fileStream.get();
        if (ch == EOF)
            break;
        seed += char(ch);
        if (seed.length() == order)
        {
            int follow = fileStream.peek();
            if (seeds.containsKey(seed))
            {
                if (follow != EOF)
                    seeds[seed].add(follow);
                frequently[seed]++;
            }
            else
            {
                Vector<char> vector;
                if (follow != EOF)
                    vector.add(follow);
                seeds.add(seed, vector);
                frequently.add(seed, 1);
            }
            seed = seed.substr(1);
        }
    }

    fileStream.close();
    return initSeed(frequently);
}

string initSeed(Map<int> &frequently)
{
    string seed;
    int frequency = 0;
    Map<int>::Iterator iter = frequently.iterator();

    while (iter.hasNext())
    {
        string key = iter.next();
        int value = frequently[key];
        if (value > frequency)
        {
            seed = key;
            frequency = value;
        }
    }

    return seed;
}

void writeRandom(Map<Vector<char>> &seeds, string initSeed)
{
    Randomize();
    string seed = initSeed;
    string randomFile = initSeed;
    while (randomFile.length() < 2000)
    {
        Vector<char> vector = seeds[seed];

        if (vector.size() < 1)
        {
            break;
        }
        int randomIdx = RandomInteger(0, vector.size() - 1);
        char ch = vector[randomIdx];
        randomFile += ch;
        seed = seed.substr(1) + ch;
    }
    cout << randomFile;
}