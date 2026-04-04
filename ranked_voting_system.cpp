#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Pair
{
    int winner;
    int loser;
    int strength;
};
/*
Time Complexity Analysis

Let:
C = number of candidates
V = number of voters

1) Recording Votes:
O(V * C^2)

2) Creating Pairs:
O(C^2)

3) Sorting Pairs:
O(C^2 log C)

4) Locking Pairs (DFS involved):
O(C^3)

5) Finding Winner:
O(C^2)

Overall Worst-Case:
O(V * C^2 + C^3)

Space Complexity:
O(C^2)
*/

class RankedVotingSystem
{
private:
    int candidateCount;
    int voterCount;

    vector<string> candidates;
    unordered_map<string, int> nameToIndex;

    vector<vector<int>> preferences;
    vector<vector<bool>> locked;
    vector<Pair> pairs;

    // Cycle Detection 
    bool createsCycle(int start, int current)
    {
        if (current == start)
            return true;

        for (int i = 0; i < candidateCount; i++)
        {
            if (locked[current][i])
            {
                if (createsCycle(start, i))
                    return true;
            }
        }
        return false;
    }

public:
    // Initialize Election 
    void initialize()
    {
        cout << "Enter number of candidates: \n";
        cin >> candidateCount;

        while (candidateCount < 2)
        {
            cout << "At least 2 candidates required. Re-enter: ";
            cin >> candidateCount;
        }

        cout << "Enter number of voters: \n";
        cin >> voterCount;

        candidates.resize(candidateCount);
        preferences.assign(candidateCount, vector<int>(candidateCount, 0));
        locked.assign(candidateCount, vector<bool>(candidateCount, false));

        for (int i = 0; i < candidateCount; i++)
        {
            string name;
            cout << "Enter candidate name " << i + 1 << ": \n";
            cin >> name;

            if (nameToIndex.count(name))
            {
                cout << "Duplicate candidate name. Try again.\n";
                i--;
                continue;
            }

            candidates[i] = name;
            nameToIndex[name] = i;
        }
    }

    // Record Votes 
    void recordVotes()
    {
        for (int v = 0; v < voterCount; v++)
        {
            cout << "\nVoter " << v + 1 << " ranking:\n";

            vector<int> ranking(candidateCount);
            vector<bool> used(candidateCount, false);

            for (int i = 0; i < candidateCount; i++)
            {
                string name;
                cin >> name;

                if (!nameToIndex.count(name))
                {
                    cout << "Invalid candidate. Re-enter.\n";
                    i--;
                    continue;
                }

                int index = nameToIndex[name];

                if (used[index])
                {
                    cout << "Candidate already ranked. Re-enter.\n";
                    i--;
                    continue;
                }

                ranking[i] = index;
                used[index] = true;
            }

            // Update preference matrix
            for (int i = 0; i < candidateCount; i++)
            {
                for (int j = i + 1; j < candidateCount; j++)
                {
                    preferences[ranking[i]][ranking[j]]++;
                }
            }
        }
    }

    //  Create Pairs
    void createPairs()
    {
        for (int i = 0; i < candidateCount; i++)
        {
            for (int j = i + 1; j < candidateCount; j++)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs.push_back({i, j, preferences[i][j] - preferences[j][i]});
                }
                else if (preferences[j][i] > preferences[i][j])
                {
                    pairs.push_back({j, i, preferences[j][i] - preferences[i][j]});
                }
            }
        }
    }

    // Sort Pairs
    void sortPairs()
    {
        sort(pairs.begin(), pairs.end(),
             [](const Pair &a, const Pair &b)
             {
                 return a.strength > b.strength;
             });
    }

    // Lock Pairs 
    void lockPairs()
    {
        for (const Pair &p : pairs)
        {
            if (!createsCycle(p.winner, p.loser))
            {
                locked[p.winner][p.loser] = true;
            }
        }
    }

    // Print Winner
    void printWinner()
    {
        for (int i = 0; i < candidateCount; i++)
        {
            bool hasIncoming = false;

            for (int j = 0; j < candidateCount; j++)
            {
                if (locked[j][i])
                {
                    hasIncoming = true;
                    break;
                }
            }

            if (!hasIncoming)
            {
                cout << "\nWinner: " << candidates[i] << endl;
                return;
            }
        }
    }

    //  Run Entire System 
    void run()
    {
        initialize();
        recordVotes();
        createPairs();
        sortPairs();
        lockPairs();
        printWinner();
    }
};

int main()
{
    RankedVotingSystem election;
    election.run();
    return 0;
}
